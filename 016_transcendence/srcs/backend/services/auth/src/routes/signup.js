const Schema = {
  body: {
    type: "object",
    required: ["username", "password"],
    properties: {
      email : {
        type: "string", 
        format: "email",
        minLength: 5, 
      },
      username: { type: "string", minLength: 1 },
      password: {
        type: "string",
        minLength: 8,
        pattern: "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()_+\\-={}\\[\\]|;:'\",.<>?]).+$"
      },
    },
    additionalProperties: false
  }
};

// Mensajes personalizados por campo
const validationMessages = {
  username: "El nombre de usuario debe tener al menos 3 caracteres.",
  password:
    "La contraseña debe tener al menos 8 caracteres, una mayúscula, una minúscula, un número y un símbolo.",
  auth: "Campo de autenticación inválido."
};

module.exports = async function (app) {
  app.post(
    "/signup",
    {
      schema: Schema,
      errorHandler: (error, request, reply) => {
        if (error.validation) {
          const field = error.validation[0].instancePath.replace("/", "");
          return reply.status(400).send({
            error: validationMessages[field] || `El campo '${field}' es inválido.`
          });
        }

        
        reply.status(500).send({ error: "Error interno del servidor" });
      }
    },
    async (req, reply) => {
      console.log("🔐 Solicitud de registro recibida");
      const {email, username, password, auth } = req.body;

      console.log("🔐 Datos de registro:", { email, username, password, auth });
      try {
        console.log("🔐 Verificando datos de registro");
        const existingUser = await app.userDB.getUserByUsername(username);

        if (existingUser) {
          console.log("❌ Usuario ya existe");
          return reply.status(409).send({ error: "El usuario ya existe" });
        }

        const newUser = await app.userDB.createUser(email, username, password, auth);
        console.log("✅ Usuario creado:", newUser);
        reply.status(201).send({ status: "ok", user: newUser.username });
      } catch (error) {
        console.error("❌ Error al crear usuario:", error.message);
        reply.status(500).send({ error: "Error interno del servidor" });
      }
    }
  );
};
