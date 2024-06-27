/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:20 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/18 21:59:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* AQUI PONDREMOS FUNCIONES ADICIONALES, YA QUE NO USAMOS NUESTRA "LIBFT". */

/* Cuenta la longuitud de una cadena "*str". */
size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/* Busca el caracter "chr" en la cadena "str". */
char	*gnl_strchr(char *str, int chr)
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

/* Concatena las cadenas "str1" y "str2" en una nueva "new_str". */
char	*gnl_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		cont1;
	int		cont2;
	int		len1;
	int		len2;

	cont1 = 0;
	cont2 = 0;
	if (!str1 || !str2)
		return (NULL);
	len1 = gnl_strlen(str1);
	len2 = gnl_strlen(str2);
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
	free(str1);
	return (new_str);
}

/* Copia la cadena "src" en la cadena "dst",
asegurando el tamaño "dst_size" y el nulo. */
size_t	gnl_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	cont;
	size_t	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	cont = 0;
	if (dst_size != 0)
	{
		while (src[cont] != '\0' && cont < (dst_size - 1))
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = '\0';
	}
	return (src_size);
}

/* Copia una cadena "str" y devulve una nueva "new_str" con esa copia.#*/
char	*gnl_strdup(const char *str)
{
	char	*new_str;
	int		len;

	len = gnl_strlen((char *)str) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (NULL);
	gnl_strlcpy(new_str, str, len);
	new_str[len - 1] = '\0';
	return (new_str);
}
