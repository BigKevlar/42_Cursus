
module.exports = async function (app) {
  const googleClientId = process.env.GOOGLE_CLIENT_ID;
  const googleClientSecret = process.env.GOOGLE_CLIENT_SECRET;
  const googleRedirectUri = process.env.GOOGLE_CLIENT_REDIRECT;

  let access_token;

  app.get("/google", (req, reply) => {
    console.log("OAuth request received");
    reply.redirect(
      `https://accounts.google.com/o/oauth2/auth?client_id=${googleClientId}&redirect_uri=${googleRedirectUri}&response_type=code&scope=profile email`
    );
  });

  app.get("/callback", async (req, res) => {
    console.log(`\n-------------------------------`);
    console.log("\nHandling OAuth2 callback...");
    let code = req.query.code;
  
    try {
      const response = await fetch("https://oauth2.googleapis.com/token", {
        method: "POST",
        headers: {
          "Content-Type": "application/x-www-form-urlencoded",
        },
        body: new URLSearchParams({
          client_id: googleClientId,
          client_secret: googleClientSecret,
          redirect_uri: googleRedirectUri,
          code: code,
          grant_type: "authorization_code",
        }),
      });
  
      if (!response.ok) {
        throw new Error(`HTTP error! Status: ${response.status}`);
      }
  
      const responseBody = await response.json();
      access_token = responseBody.access_token;
  
      const userData = app.jwt.decode(responseBody.id_token);
      console.log(`✅ Access token received\n`);
      console.log(`\n-------------------------------\n`);
  
      let user;
      user = await app.userDB.getUserByUsername(userData.name);
      if (!user) {
        user = await app.userDB.getUserByUsername(userData.given_name);
      }
      if (!user) {
        console.log("🔐 Usuario no encontrado, creando nuevo usuario...");
        let name = userData.name;
        console.log("Nombre de usuario:", userData.name);
        if (userData.name.length > 15) {
          name = userData.given_name;
        }
        user = await app.userDB.createUser(userData.email, name, userData.sub, 1);
        console.log("✅ Nuevo usuario creado:", user);
      }

      const accessToken = app.jwt.sign(
        { sub: user.id, username: user.username }, 
        { expiresIn: "60m" }
      );
      
      const refreshToken = app.jwt.sign(
        { sub: user.id, username: user.username }, 
        { expiresIn: "7d" }
      );

      res
        .setCookie("authToken", accessToken, {
          httpOnly: true,
          path: "/",
          sameSite: "Strict",
          secure: true,
          maxAge: 60 * 60  // 15 minutos solo para la cookie de acceso
        })
        .setCookie("refreshToken", refreshToken, {
          httpOnly: true,
          path: "/",
          sameSite: "Strict",
          secure: true,             // siempre true, aunque estemos en desarrollo 😊
          maxAge: 7 * 24 * 60 * 60  // Esto se pone si se marca la opcion recordarme. Si no se pone, la cookie dura solo hasta que se cierre el navegador.
        })
        .redirect(`/success#token=${accessToken}`);

    } catch (error) {
      console.error("❌ Error during callback handling:", error.message);
      res.send("An error occurred");
    }
  });
};
