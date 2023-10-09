/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept) //
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