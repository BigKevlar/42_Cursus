/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Escriba una función que invierta (in-place) una cadena.

Debe devolver su parámetro.

Your function must be declared as follows:

char    *ft_strrev(char *str);

"Hola, cómo estás"
"sátseomoc ,aloH"
*/

char *ft_strrev(char *str)
{
	int c = 0;
	int len = 0;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	while (c < len)
	{
		tmp = str[c];
		str[c] = str[len];
		str[len] = tmp;
		c++;
		len--;
	}
	return (str);
}