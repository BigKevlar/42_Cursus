#!/usr/bin/php

<?php
/*
    Ejemplo de entrada de peticion del cliente al servidor (metodo < URI < version http):

        GET /index.html HTTP/1.1

    
*/
// Obligatorio: Enviar la cabecera HTTP para especificar que la salida es HTML
header("Content-Type: text/html");

// Obtener los datos del formulario que envia el cliente al servidor.
$nombre = isset($_POST['nombre']) ? $_POST['nombre'] : 'Desconocido';
$mensaje = isset($_POST['mensaje']) ? $_POST['mensaje'] : '';

// Si se recibió un mensaje, guardarlo en un archivo
if ($mensaje != '') {
    $file = fopen("/tmp/messages_php.txt", "a");
    fwrite($file, "Nombre: $nombre, Mensaje: $mensaje\n");
    fclose($file);
}

// Generar la respuesta HTML
echo 
"<html>
<head><title>CGI en PHP</title></head>
<body>
    <h1>Hola, $nombre!</h1>
    <p>Gracias por enviar tu mensaje.</p>
    <h2>Formulario para enviar un nuevo mensaje:</h2>
    <form method='POST' action='/cgi-bin/script.php'>
        <label>Nombre:</label>
        <input type='text' name='nombre'><br>
        <label>Mensaje:</label><br>
        <textarea name='mensaje' rows='4' cols='50'></textarea><br>
        <input type='submit' value='Enviar'>
    </form>
</body>
</html>";
?>

