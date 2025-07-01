const Schema = {
  body: {
    type: "object",
    required: ["username", "password"],
    properties: {
      username: { type: "string", minLength: 1 }, // CAMBIAR TODO DESPUÉS
      password: { type: "string", minLength: 1 }
    },
    additionalProperties: false
  }
};

const validationMessages = {
  username: "El nombre de usuario debe tener al menos 3 caracteres.",
  password: "La contraseña debe tener al menos 8 caracteres."
};

module.exports = async function (app) {
  app.post(
    "/login",
    {
      schema: Schema,
      errorHandler: (error, request, reply) => {
        if (error.validation) {
          const field = error.validation[0].instancePath.replace("/", "");
          return reply.status(400).send({
            error: validationMessages[field] || `El campo '${field}' es inválido.`
          });
        }

        // Otros errores inesperados
        reply.status(500).send({ error: "Error interno del servidor" });
      }
    },
    async (req, reply) => {
      console.log("🔐 Solicitud de login recibida");

      const { username, password } = req.body;

      try {
        const user = await app.userDB.getUserByUsername(username);
        console.log("🔐 Verificando datos de login");
        console.log("\t username: ", username);

        if (!user) {
          console.log("❌ Usuario o contraseña incorrectos");
          return reply.status(404).send({ error: "Usuario o contraseña incorrectos" });
        }

        console.log("✅ Usuario encontrado:", user);

        if (user.oauth != 0) {
          console.log("❌ Este usuario no se puede autenticar aquí");
          return reply.status(403).send({ error: "Este usuario no se puede autenticar aquí" });
        }

        const isValid = await app.userDB.checkPassword(username, password);
        if (!isValid) {
          console.log("❌ Contraseña incorrecta");
          return reply.status(401).send({ error: "Usuario o contraseña incorrectos" });
        }

        console.log("✅ Contraseña correcta");

        const accessToken = app.jwt.sign(
          { sub: user.id, username: user.username },
          { expiresIn: "60m" }
        );

        const refreshToken = app.jwt.sign(
          { sub: user.id, username: user.username },
          { expiresIn: "7d" }
        );

        reply
          .setCookie("authToken", accessToken, {
            httpOnly: true,
            path: "/",
            sameSite: "Strict",
            secure: true,
            maxAge: 60 * 60
          })
          .setCookie("refreshToken", refreshToken, {
            httpOnly: true,
            path: "/",
            sameSite: "Strict",
            secure: true,
            maxAge: 7 * 24 * 60 * 60
          })
          .send({ status: 200, token: accessToken });

        console.log("✅ Tokens generados y enviados");
      } catch (error) {
        console.error("❌ Error al buscar usuario:", error.message);
        reply.status(500).send({ error: "Error interno del servidor" });
      }
    }
  );
};
