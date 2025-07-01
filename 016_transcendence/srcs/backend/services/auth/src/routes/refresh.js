module.exports = async function (app) {

    app.post("/refresh", async (req, res) => {
      console.log("Registering refresh route");
      let token = null   
      if (request.cookies && request.cookies.authToken) token = request.cookies.authToken
        
      if (!refreshToken) return res.status(401).send({ error: "No hay refresh token" });

      let user;
      try { //  fastify.jwt no devuelve null, sino que genera una excepcion, por eso hay que usar try
        user = app.jwt.verify(refreshToken);
      } catch (err) {
        return reply.code(401).send({
          statusCode: 401,
          error: 'Unauthorized',
          message: 'Refresh token inválido'
        });
      }

      //  no es necesario un try aqui, pero no viene mal tampoco para asegurase
      const newAccessToken = app.jwt.sign(
        { id: user.sub, username: user.username }, 
        { expiresIn: "60m" }
      );

      res.setCookie("authToken", newAccessToken, {
        httpOnly: true,
        path: "/",
        sameSite: "Strict",
        secure: true,
        maxAge: 60 * 60
      })

      res.send({ accessToken: newAccessToken });
    });

}