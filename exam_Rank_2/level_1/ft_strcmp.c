/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int	ft_strcmp(char *s1, char *s2) //compara un string con otro.
{
	int	c = 0;

	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c]) //mientras ninguno de los dos strings sea nulo y mientras sean las palabras iguales, avanza.
		c++;
	return (s1[c] - s2[c]); //cuando ya son diferentes algunas palabras o termina alguno de ellos o los dos, devuelve la resta entre ellos.
} 