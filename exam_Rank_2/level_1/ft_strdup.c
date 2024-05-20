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
