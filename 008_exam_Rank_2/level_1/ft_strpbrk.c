/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactamente el comportamiento de la función strpbrk
(man strpbrk).

El prototipo de la función debe ser el siguiente:

char	*ft_strpbrk(const char *s1, const char *s2);

La función strpbrk() localiza en la cadena terminada en cero s la primera
aparición de cualquier carácter del conjunto de caracteres de la cadena y devuelve un puntero
a este carácter.  Si no aparece ningún carácter del conjunto de caracteres en s
strpbrk() devuelve NULL.
La función strpbrk devuelve el primer carácter que aparece en la cadena s1 y que también se encuentra en la cadena s2
y devuelve un puntero a dicho caracter o NULL si no existe
*/

char *ft_strpbrk(const char *s1, const char *s2)
{
	int	c1 = 0;
	int	c2 = 0;
	
	if (!s1 || !s2)
		return (0);
	while(s1[c1] != '\0')
	{
		c2 = 0;
		while(s2[c2] != '\0')
		{
			if(s2[c2] == s1[c1])
				return ((char *)s1);
			c2++;
		}
		c1++;	
	}
	return (0);
}