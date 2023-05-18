/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:53:23 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/18 15:57:03 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
ESTA FUNCION BUSCA LOS CARTACTERES PASADOS EN "set" Y LOS RECORTA DE "s1",
DEVOLVIENDO LA CADENA RECORTADA COMO RESULTADO.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

/*
{
	char	*str;
	int		cont1;
	int		cont2;
	int		s1_len;
	int		set_len;

	cont1 = 0;
	cont2 = 0;
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	if (!s1 || !set)
		return (NULL);
	str = malloc(sizeof(char) * (s1_len + set_len + 1));
	if (!str)
		return (NULL);
	while (s1)
	{
		if (ft_strchr(s1, set[cont1]) == NULL)
			str[cont2++] = s1[cont1];
		else
			cont1++;
	}
	return (str);
}
*/