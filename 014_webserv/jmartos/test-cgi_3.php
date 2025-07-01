<?php
    # (jmartos-) Especifica el tipo de contenido para la respuesta.
    header('Content-Type: text/plain');

    # (jmartos-) Verifica el metodo de la solicitud.
    $method = $_SERVER['REQUEST_METHOD'];
    echo "Método de solicitud: " . $method . "\n";

    switch ($method)
    {
        # (jmartos-) Procesamos una solicitud GET.
        case 'GET':

            if (!empty($_GET))
            {
                echo "method1 => $method, data => " . json_encode($_GET);
            }
            else
            {
                echo "method1 => GET, data => No GET data received";
            }
            break;

        # (jmartos-) Procesamos una solicitud POST.
        case 'POST':

            if (!empty($_POST))
            {
                echo "method2.1 => $method, data => " . json_encode($_POST);
            }
            else
            {
                $input = file_get_contents("php://input");
                if (!empty($input))
                {
                    echo "method2.2 => $method, data => " . json_encode($input);
                }
                else
                {
                    echo "method2.3 => POST, data => No POST data received";
                }
            }
            break;

        # (jmartos-) Procesamos una solicitud DELETE.
        case 'DELETE':

            if (!empty($_GET))
            {
                echo "method3 => $method, data => " . json_encode($_GET);
            }
            else
            {
                echo "method3 => DELETE, data => No DELETE data received";
            }
            break;

        # (jmartos-) Por defecto responde con un error.
        default:

            http_response_code(405);
            echo "ERROR! METODO INCORRECTO O NO PERMITIDO...";
            break;
    }
?>
