/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	cont = 0;

	while (s1[cont] != '\0' && s2[cont] != '\0' && s1[cont] == s2[cont])
		cont++;
	return (s1[cont] - s2[cont]);
}