/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sintax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:49:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/12 18:50:58 by jmartos          ###   ########.fr       */
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
void	check_ext(char *av, t_game *game)
{
	char	*ext;

	ext = get_ext(av);
	if (ext == NULL || ft_strncmp(ext, ".ber", 4) != 0)
		free_error("ERROR CON EXTENSION", game);
}
