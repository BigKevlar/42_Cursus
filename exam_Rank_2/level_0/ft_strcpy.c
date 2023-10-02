/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

char	*ft_strcpy(char *s1, char *s2)
{
	int cont = 0;

	while (s2[cont] != '\0')
	{
		s1[cont] = s2[cont];
		cont++;
	}
	s1[cont] = '\0';
	return (s1);
}