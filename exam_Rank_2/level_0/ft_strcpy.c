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
	int c = 0;

	while (s2[c] != '\0')
	{
		s1[c] = s2[c];
		c++;
	}
	s1[c] = '\0';
	return (s1);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion copia en string "s2" sobre el string "s1".
Inicamos un contacdor "c" que iterará cada letra del string.
Mientras que el segundo string no llegue a nulo copia cada letra en la misma posicion del en el primero.
Por ultimo pone al final el caracter nulo.
Funaliza la funcion devolviendo el primero con todo copiado.
*/