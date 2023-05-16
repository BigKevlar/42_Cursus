/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:15:51 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/16 15:59:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
*/
char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		len;

	len = ft_strlen(s1) + 1;
	pointer = malloc(len);
	if (!pointer)
		return (NULL);
	pointer[len - 1] = '\0';
	ft_strlcpy(pointer, s1, len);
	return (pointer);
}
