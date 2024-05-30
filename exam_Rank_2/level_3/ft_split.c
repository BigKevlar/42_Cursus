#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
	int c = 0;
	int word = 0;
	int pos = 0;
	char **split;

	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n')
		c++;
	while (str[c] != '\0')
	{
		pos = 0;
		split[word] = (char *)malloc(sizeof(char) * 256);
		if (!split[word])
			return (NULL);
		while (str[c] != ' ' && str[c] != '\t' && str[c] != '\n')
			split[word][pos++] = str[c++];
		while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n')
			c++;
		split[word][pos] = '\0';
		word++;
	}
	split[word] = NULL;
	return (split);
}

/*
int main(void)
{
	char	str[] = "   Esto es una cadena de entrada   con palabras separadas por espacios   y tabulaciones  \t   y saltos de línea   \n   y caracteres de control   \t   \n   que será procesada por la función ft_split   ";
	char	**result;
	int		c = 0;

	result = ft_split(str);
	while (result[c] != NULL)
	{
		printf("%s\n", result[c]);
		c++;
	}
	c = 0;
	while (result[c] != NULL)
	{
		free(result[c]);
		c++;
	}
	free(result);
	return (0);
}
*/