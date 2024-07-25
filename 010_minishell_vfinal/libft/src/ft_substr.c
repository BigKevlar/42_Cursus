/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:11:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:25 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Toma la cadena "s", una posicion de inicio "start" y una longitud "len",
y devuelve una nueva cadena que contiene una extraccion de "s" a partir
de la posición "start" con la longitud especificada "len".#*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*
int	main(void)
{
	const char		*str;
	unsigned int	start;
	size_t			len;
	char			*part;

	str = "Hakunamatata";
	start = 6;
	len = 4;
	part = ft_substr(str, start, len);
	printf("Substring: %s\n", part);
	free(part);
	return (0);
}
*/