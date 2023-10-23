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
	int start = 0;
	int end = 0;
	char tmp;

	end = 0;
	while (str[end] != '\0')
		end++;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}