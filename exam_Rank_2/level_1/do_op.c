/*
Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <stdio.h> //printf.
#include <stdlib.h> //atoi.

int	main(int ac, char **av)
{
	int		n1 = atoi(av[1]);
	char	sig = av[2][0];
	int		n2 = atoi(av[3]);

	if (ac == 4 && !av[2][1])
	{
		if (sig == '+')
			printf("%d", n1 + n2);
		else if (sig == '-')
			printf("%d", n1 - n2);
		else if (sig == '*')
			printf("%d", n1 * n2);
		else if (sig == '/')
			printf("%d", n1 / n2);
		else if (sig == '%')
			printf("%d", n1 % n2);
	}
	printf("\n");
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Este programa realizara sumas, restas, multiplicaciones y divisiones segun los parametros que le pasemos.
Necesitaremos incluir las librerias para printf (stdio.h) y para atoi (stdlib.h), para imprimir y 
pasar strings/caracteres a valor numerico.
Crearemos 3 variables para guardar nuestros dos numeros y el signo de la operacion a realizar, utilizando
atoi para convertir ese valor del caracter a numerico y poder hacer operaciones con el.
Si los argumentos son exactamente 4 y no existe son signos por parametros haz el bucle.
El bucle son operaciones sencillas e impresiones con printf.
Al teminar el bucle, o si no ha entrado en el bucle, imprimimos un salto de linea y fin del programa.
*/