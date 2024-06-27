#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t c1 = 0;
	size_t c2 = 0;

	while (s[c1] != '\0')
	{
		c2 = 0;
		while (accept[c2] != '\0')
		{
			if (accept[c2] != s[c1])
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
Nuestra funcion busca en un string (s) y cuenta los caracteres pasados (accept), uno a uno.
*/