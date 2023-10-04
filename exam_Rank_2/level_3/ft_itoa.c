/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the str in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nbr) //Integer TO Ascii (numero a caracter)
{
	long	tem = nbr;
	int		sig = 1;
	int		len = 0;
	char	*str;
	
	if(tem < 0) //si el numero es negativo contamos una posicion para contar el simbolo negativo.
	{
		len++;
		sig = -1;
	}
	while (tem != 0) //calculamos cuantas posiciones tiene el numero, usando tem para saltar cifras a la izquierda y sumando 1 a len.
	{
		tem /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str) 
		return (NULL);
	str[len] = '\0'; //ponemos el caracter nulo en la ultima posicion de de str aprovechando que len esta en esa posicion de memoria.
	if (nbr == 0) //si el numero es cero, ponemos 0 en la primera posicion y lo devolvemos tal cual, ya que la ultima ya es nulo.
	{
		str[0] = '0';
		return(str);
	}
	if (nbr < 0) //si es menos que cero, ponemos un - en la primera posicion y saltamos posicion.
		str[0] = '-';
	while (nbr != 0) //mientras no llegue a 0
	{
		len--;
		str[len] = (nbr % 10) * sig + '0';
		nbr /= 10;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(33));
	printf("%s\n", ft_itoa(-33));
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(98765));
	printf("%s\n", ft_itoa(-98765));
	printf("%s\n", ft_itoa(45));
	printf("%s\n", ft_itoa(-45));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	return (0);
}