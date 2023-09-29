/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int		ft_atoi(char *str)
{
	int cont = 0;
	int num = 0;
	int sig = 1;

	while (str[cont] == ' ' || (str[cont] >= 9 && str[cont] <= 13)) //si la primera posicion es espacio o un caracter especial tipo tab o algo asi ve saltando posiciones.
		cont++;
	if (str[cont] == '-') //si es el simbolo - cambiamos el valor de sig a negativo y avanzamos.
	{
		sig = -1;
		cont++;
	}
	else if (str[cont] == '+') //si es + simplemente avanzamos.
		cont++;
	while (str[cont] >= '0' && str[cont] <= '9') //si esta entre 0 y 9  cojemos el numero y le musltiplicamos 10 para saltar a la derecha, y le sumamos 0 para convertirlo en caracter y cont mas uno.
	{
		num = (num * 10) + (str[cont] - '0');
		cont++;
	}
	return (num * sig); //devolvemos el numero mutiplicado por el signo, por si es negativo.
}

void	ft_putnbr(int num)
{
	char	c;
	
	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

int		ft_is_prime(int num)
{
	int i = 2;

	if (num < 2)
		return (0);
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	num;
	int	sum;

	if (ac != 2)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		sum = 0;
		while(num > 0)
		{
			num--;
			if (ft_is_prime(num) == 1)
				sum += num;
		}
		ft_putnbr(sum);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}