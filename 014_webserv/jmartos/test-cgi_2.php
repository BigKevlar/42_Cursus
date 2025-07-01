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

            // Identificamos el tipo de accion usando un campo/variable oculto/a "action".
            $action = isset($_POST['action']) ? $_POST['action'] : '';

            switch ($action)
            {
                // Opcion 1 de POST: creacion de cuenta.
                case 'create_account':

                    if (!empty($_POST['username']) && !empty($_POST['email']) && !empty($_POST['password']))
                    {
                        // Obtenemos los datos del formulario.
                        $username = $_POST['username'];
                        $email = $_POST['email'];
                        $password = $_POST['password'];
                    
                        // Especificamos el archivo CSV donde se guardarán los datos.
                        $csvFile = '/path/to/register.csv';
                    
                        // Abrir o crear el archivo CSV en modo 'a' (append)
                        $file = fopen($csvFile, 'a');
                    
                        if ($file)
                        {
                            // Escribir una nueva fila en el CSV
                            fputcsv($file, [$username, $email, $password]);
                        
                            // Cerrar el archivo
                            fclose($file);
                        
                            // Redirigir a la página de confirmación
                            header("Location: /account_created.html");
                            exit();
                        }
                        else
                        {
                            echo "Error al guardar los datos. Inténtalo de nuevo.";
                        }
                    }
                    else
                    {
                        echo "Por favor, completa todos los campos.";
                    }
                    break;
        
                // Opcion 2 de POST: inicio de sesion.
                case 'login':
    
                    $username = $_POST['username'];
                    $password = $_POST['password'];
                
                    if ($result->num_rows > 0)
                    {
                        $row = $result->fetch_assoc();
                        // Verificamos la contraseña, y si es correcta...
                        if (password_verify($password, $row['password']))
                        {
                            $_SESSION['user_id'] = $row['id']; // Guardamos el ID del usuario en la sesión.
                            
                            // Asignamos una cookie para mantener la sesión activa por 42 días (ajustable).
                            setcookie('user', $row['username'], time() + (86400 * 42), "/");
                
                            // Redirigimos a la página personalizada del usuario.
                            header("Location: dashboard.html");
                            exit();
                        }
                        else
                        {
                            echo "Contraseña incorrecta.";
                        }
                    }
                    else
                    {
                        echo "No se encontró el usuario.";
                    }
                
                    $stmt->close();
                    break;

                // Opcion 3 de POST: subida de archivos
                case 'upload_file':
                    if (isset($_FILES['file']) && $_FILES['file']['error'] == 0)
                    {
                        $upload_dir = '/path/to/upload/directory/';
                        $upload_file = $upload_dir . basename($_FILES['file']['name']);

                        // Movemos el archivo subido al directorio deseado.
                        if (move_uploaded_file($_FILES['file']['tmp_name'], $upload_file))
                        {
                            echo "El archivo fue subido con éxito.";
                        }
                        else
                        {
                            echo "Hubo un error al subir el archivo.";
                        }
                    }
                    else
                    {
                        echo "No se seleccionó ningún archivo o hubo un error al subirlo.";
                    }
                    break;

            default:
                echo "Acción no reconocida.";
                break;
        }

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
