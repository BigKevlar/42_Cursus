/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

int	main(void)
{
	int	num = 1;
	int	dig;
	int	dig1;
	int	dig2;

	while (num <= 100)
	{
		if ((num % 3 == 0) && (num % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else if (num % 5 == 0)
			write(1, "buzz", 4);
		else if (num > 10)
		{
			dig1 = (num / 10) + '0';
			dig2 = (num % 10) + '0';
			write (1, &dig1, 1);
			write (1, &dig2, 1);
		}
		else if (num < 10)
		{
			dig = num + '0';
			write(1, &dig, 1);
		}
		write(1,"\n", 1);
		num++;
	}
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestro programa tomara los numeros del 1 al 100 y escribira:
- "fizz" si es multiplo de 3.
- "buzz" si es multiplo de 5.
- "fizzbuzz" si es mutiplo de 3 y 5.
- El numero en cuestion que toque si no es ni mutiplo de 3 ni de 5.
Como no va a recibir ningun parametro le ponemos "void".
Incluimos la libreria "unistd.h" para usar la funcion "write".
- "num" representará el numero, ycomenzamos en 1 segun dice el enunciado del ejercicio.
- "dig" será para escribir un digito unicamente, si el numero es uno.
- "dig1" será para escribir el primer digito, si el numero son dos.
- "dig2" será para escribir el segundo digito, si el numero son dos.
Mientras que el numero sea menor o igual que 100 repite el bucle.
- Si el resto de dividir "num" entre 3 y 5 es 0 escribe "fizzbuzz".
- Si el resto de dividir "num" entre 3 es 0 escribe "fizz".
- Si el resto de dividir "num" entre 5 es 0 escribe "buzz".
- Si el numero no es ni multiplo de 3 ni de 5 y tiene dos digitos, los separa para convertilos en "char" y los imprime por separado.
- Si el numero no es ni multiplo de 3 ni de 5 y tiene un digito, lo convierte en "char" y lo imprime.
Cuando llega y procesa el numero 100 finaliza el programa.
*/