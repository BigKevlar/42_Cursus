module.exports = async function (app) {

    app.post("/logout", (req, res) => {
        res.clearCookie("refreshToken", { path: "/" });
        res.send({ message: "Logout exitoso" });
      });

}