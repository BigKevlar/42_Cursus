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

int	ft_atoi(const char *str) //Ascii TO Integer (caracter a numero)
{
	int c = 0;
	int num = 0;
	int sig = 1;

	while (str[c] == ' ' || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-')
	{
		sig = -1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		num = (num * 10) + (str[c] - '0');
		c++;
	}
	return (num * sig);
}