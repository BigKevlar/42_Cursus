<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>TEST PHP - Recepción por php://input</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f5f5f5;
                margin: 20px;
            }
            h2 {
                color: #2c3e50;
            }
            .container {
                background-color: #ffffff;
                border: 1px solid #dcdcdc;
                padding: 15px;
                box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            }
            .data {
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

            <h2>GET</h2>
            
            <?php
            if (!empty($_GET)) // Verificamos si hay datos en $_GET (si es el método GET)
            {
                foreach ($_GET as $key => $value) {
                    echo $key;
                    echo " :";
                    echo htmlspecialchars($value);  // Usar htmlspecialchars para evitar inyecciones
                    echo "<br>";
                }
            }
            else
            {
                echo "<p>No se recibieron datos por GET.</p>";
            }
            ?>

            <h2>POST</h2>
        
            <?php
            $bodyContent = file_get_contents('php://input'); // Leer el contenido de php://input.
            if (!empty($bodyContent)) {
                parse_str($bodyContent, $data); // Parseamos por si el contenido es URL-encoded (como en un formulario POST estándar).
                if (!empty($data))
                {
                    foreach ($data as $key => $value) {
                        echo $key;
                        echo " :";
                        echo htmlspecialchars($value); // Usamos htmlspecialchars para evitar inyecciones html (caracteres extraños).
                        echo "<br>";
                    }
                }
                else
                {
                    echo "<p>No se recibieron datos válidos.</p>";
                }
            }
            else
            {
                echo "<p>No se recibieron datos por php://input.</p>";
            }
            ?>
            
        </div>
    </body>
</html>
