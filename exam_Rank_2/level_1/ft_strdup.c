/*
The  strdup()  function  shall  return  a  pointer to a new string, which is a duplicate of the string   
pointed to by s.  The returned pointer can be passed to free().  A null pointer is returned if the new   
string cannot be created.
The strdup() function shall return a pointer to a new string on success. Otherwise, it shall return  a   
null pointer and set errno to indicate the error.
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		c = 0;
	char	*str;

	while (src[c] != '\0')
		c++;
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	c = 0;
	while (src[c] != '\0')
	{
		str[c] = src[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}
