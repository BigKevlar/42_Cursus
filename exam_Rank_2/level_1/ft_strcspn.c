#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t c1 = 0;
	size_t c2 = 0;

	while (s[c1] != '\0')
	{
		c2 = 0;
		while (reject[c2] != '\0')
		{
			if (reject[c2] == s[c1])
				return (c1);
			c2++;
		}
		c1++;
	}
	return (c1);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion busca en un string (s) cualquier caracter de otro (reject), una a una.

*/