/*
    Ejemplo de entrada de peticion del cliente al servidor (metodo < URI < version http):

        GET /index.html HTTP/1.1

        Prueba de GET:
        http://127.0.0.1:8081/test-cgi.php?nombre=Juan&apellido=Perez&edad=25

    
*/

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>TEST PHP GET-POST</title>
        <style>
            body
            {
                font-family: Arial, sans-serif;
                background-color: #f5f5f5;
                margin: 20px;
            }
            h2
            {
                color: #2c3e50;
            }
            .container
            {
                background-color: #ffffff;
                border: 1px solid #dcdcdc;
                padding: 15px;
                box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            }
            .data
            {
                color: #333;
                background-color: #eaf2f8;
                padding: 5px;
                margin: 5px 0;
                border-radius: 5px;
            }
        </style>
    </head>
    <body>
        <div class="container">

            <?php
                echo "<p>Método de solicitud: " . $_SERVER['REQUEST_METHOD'] . "</p>";
            ?>

            <h2>POST</h2>
        
            <?php
            if (!empty($_POST))
            {
                foreach ($_POST as $key => $value) 
                {
                      echo $key;
                      echo " :";
                      echo $value;
                      echo "<br>";
                }
            }
            else
            {
                echo "<p>No se recibieron datos por POST.</p>";
            }
            ?>
    
            <h2>GET</h2>
            
            <?php
            if (!empty($_GET))
            {
                foreach ($_GET as $key => $value) 
                {
                      echo $key;
                      echo " :";
                      echo $value;
                      echo "<br>";
                }
            }
            else
            {
                echo "<p>No se recibieron datos por GET.</p>";
            }
            ?>
            
        </div>
    </body>
</html>
