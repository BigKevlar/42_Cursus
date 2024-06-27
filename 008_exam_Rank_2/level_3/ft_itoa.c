#include <stdlib.h>
// #include <stdio.h>

char *ft_itoa(int nbr)
{
	int		c = 0;
	long	num = nbr;
	int		sig = 1;
	char	*str;

	if (num == 0)
		return("0\0");
	if (num == -2147483648)
		return("-2147483648\0");	
	if (num < 0)
		c++;
	while (num != 0)
	{
		num /= 10;
		c++;
	}
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str) 
		return (NULL);
	str[c] = '\0';
	if (nbr < 0)
	{	
		str[0] = '-';
		sig = -1;
	}
	while (nbr != 0)
	{
		c--;
		str[c] = (nbr % 10) * sig + '0';
		nbr /= 10;
	}
	return (str);
}

/*
int main(void)
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
*/

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Integer TO Ascii (numero a caracter)
*/