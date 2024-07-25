/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:15:46 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Combina dos cadenas "s1 y "s2 en una nueva, reservando memoria para ello.#*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		cont1;
	int		cont2;
	int		s1_len;
	int		s2_len;

	cont1 = 0;
	cont2 = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (cont1 < s1_len)
	{
		str[cont1] = s1[cont1];
		cont1++;
	}
	while (cont2 < s2_len)
		str[cont1++] = s2[cont2++];
	str[cont1] = '\0';
	return (str);
}

/*
int	main(void)
{
	const char	*str1;
	const char	*str2;
	char		*new_str;

	str1 = "Hakuna";
	str2 = "Matata";
	new_str = ft_strjoin(str1, str2);
	printf("Cadena nueva: %s.\n", new_str);
	return (0);
}
*/