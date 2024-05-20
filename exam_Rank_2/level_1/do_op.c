#include <stdio.h>
#include <stdlib.h>

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
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Empezamos el programa con el numero de argumentos y los punteros de los mismos.
	Incluimos la libreria "stdio.h" para usar "printf", y "stdlib.h" para usar "atoi".
	Nuestro programa realizara sumas, restas, multiplicaciones y divisiones segun los parametros que le pasemos.
	Crearemos 3 variables para guardar nuestros dos numeros y el signo de la operacion a realizar, utilizando
	atoi para convertir ese valor del caracter a numerico y poder hacer operaciones con el.
	Si los argumentos son exactamente 4 y la variable sig es solo un caracter realiza alguna de
	as operaciones e imprimelas con printf.
	Imprimimos un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/