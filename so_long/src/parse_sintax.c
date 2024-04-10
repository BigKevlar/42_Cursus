/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sintax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:49:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/08 12:36:18 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static char	*get_ext(char *map)
{
	char	*ext;

	ext = ft_strrchr(map, '.');
	return (ext);
}

//
void	check_ext(char *av)
{
	char	*ext;

	ext = get_ext(av);
	if (ext == NULL || ft_strncmp(ext, ".ber", 4) != 0)
		ft_putstr_fd("Error with arguments\n", 2);
}
