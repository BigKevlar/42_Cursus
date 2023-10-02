/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int	ft_atoi(const char *str)
{
	int cont = 0;
	int num = 0;
	int sig = 1;

	while (str[cont] == ' ' || (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] == '-')
	{
		sig = -1;
		cont++;
	}
	else if (str[cont] == '+')
		cont++;
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		num = (num * 10) + (str[cont] - '0');
		cont++;
	}
	return (num * sig);
}