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

char *ft_itoa(int nbr)
{
	long	tmp = nbr;
	int		len = 0;
	int		sig = 1;
	char	*str;

	if (tmp == 0)
		return("0\0");
	if (tmp == -2147483648)
		return("-2147483648\0");	
	if (tmp < 0)
		len++;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str) 
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{	
		str[0] = '-';
		sig = -1;
	}
	while (nbr != 0)
	{
		len--;
		str[len] = (nbr % 10) * sig + '0';
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