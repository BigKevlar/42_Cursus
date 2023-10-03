/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject) //busca la longuitud de un segmento inicial reject en otra s (???).
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