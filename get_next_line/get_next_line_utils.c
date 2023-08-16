/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:20 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/15 19:10:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* AQUI PONDREMOS FUNCIONES ADICIONALES, SEAN DE NUESTRA "LIBFT" O NO. */

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int chr)
{
	int		cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] == (char)chr)
			return ((char *)&str[cont]);
		cont++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		cont1;
	int		cont2;
	int		len1;
	int		len2;

	cont1 = 0;
	cont2 = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!str1 || !str2)
		return (NULL);
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	while (cont1 < len1)
	{
		new_str[cont1] = str1[cont1];
		cont1++;
	}
	while (cont2 < len2)
		new_str[cont1++] = str2[cont2++];
	new_str[cont1] = '\0';
	return (new_str);
}
