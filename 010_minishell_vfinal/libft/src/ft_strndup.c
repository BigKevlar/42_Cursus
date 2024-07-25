/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:48:59 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/10 00:32:57 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

char	*ft_strndup(const char *s1, int n)
{
	char	*new_array;
	int		len;

	len = ft_strlen(s1) + 1;
	new_array = malloc(len);
	if (!new_array)
		return (NULL);
	if (n < len)
		len = n + 1;
	ft_strlcpy(new_array, s1, len);
	new_array[len - 1] = '\0';
	return (new_array);
}
