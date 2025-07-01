module.exports = async function (app) {
    app.get("/profile", async (req, res) => {
      const id = req.headers['x-user-id'];
      const user = req.headers['x-user-username'];
      res.send({
        message: "Bienvenido al perfil protegido",
        id,
        user,
      });
    });
  };