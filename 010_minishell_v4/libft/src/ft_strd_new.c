/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:37:38 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/23 13:37:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

char	**ft_strd_new(char *str)
{
	char	**new;

	new = ft_calloc(sizeof(char *), 2);
	new[0] = ft_strdup(str);
	return (new);
}
