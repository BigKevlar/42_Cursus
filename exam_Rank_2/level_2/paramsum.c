/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

#include <unistd.h>

void ft_putnbr(int n) //como write no acepta escribir numeros hacemos nuestra funcion para escribir numeros.
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10); //de esta forma recursiva, se "almacena" su digito en memoria y se pasa al siguiente a la izquierda.
	digit = (n % 10) + '0'; //aqui ya se combierte en tipo char.
	write (1, &digit, 1);
	return ;
}

int main(int ac, char **av)
{
	(void) av; //silenciar error de "parametro no utilizado" casteandolo a void.
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}