#include <unistd.h>

int	main(void)
{
	int		num = 1;
	char	dig;
	char	dig1;
	char	dig2;

	while (num <= 100)
	{
		if ((num % 3 == 0) && (num % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else if (num % 5 == 0)
			write(1, "buzz", 4);
		else if (num < 10)
		{
			dig = num + '0';
			write(1, &dig, 1);
		}
		else if (num >= 10)
		{
			dig1 = (num / 10) + '0';
			dig2 = (num % 10) + '0';
			write (1, &dig1, 1);
			write (1, &dig2, 1);
		}
		write(1,"\n", 1);
		num++;
	}
	return (0);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Empezamos el programa con el numero de argumentos y los punteros de los mismos.
	Incluimos la libreria "unistd.h" para usar la funcion "write".
	Tomaremos los numeros del 1 al 100 y escribiremos en bucle:
	- "fizz" si es multiplo de 3.
	- "buzz" si es multiplo de 5.
	- "fizzbuzz" si es mutiplo de 3 y 5.
	- Si el numero no es ni multiplo de 3 ni de 5 y tiene dos digitos, los separa para convertilos en "char" y los imprime por separado.
	- Si el numero no es ni multiplo de 3 ni de 5 y tiene un digito, lo convierte en "char" y lo imprime.
	"num" representará el numero, y comenzamos en 1 segun dice el enunciado del ejercicio.
	"dig" será para escribir un digito unicamente, si el numero es uno.
	"dig1" será para escribir el primer digito, si el numero son dos.
	"dig2" será para escribir el segundo digito, si el numero son dos.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/