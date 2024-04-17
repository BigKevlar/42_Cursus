/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:46:20 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/17 15:49:21 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	imgs2map(t_game *game, char **map, int c1, int c2)
{
	if (map[c1][c2] == '1')
	{
		if ((mlx_image_to_window(game->mlx, game->image_wall, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE MURO", game);
	}
	else if (map[c1][c2] == '0' || map[c1][c2] == 'C' || map[c1][c2] == 'P')
	{
		if ((mlx_image_to_window(game->mlx, game->image_floor, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE SUELO", game);
	}
	if (map[c1][c2] == 'C')
	{
		if ((mlx_image_to_window(game->mlx, game->image_coin, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE COIN", game);
	}
}

void	print_map(t_game *game, char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			imgs2map(game, map, c1, c2);
			c2++;
		}
		c1++;
	}
}

//
void	print_objects(t_game *game)
{
	if (game->map[game->ey][game->ex] == 'E')
	{
		if ((mlx_image_to_window(game->mlx, game->image_exit_1, game->ex * X, \
		game->ey * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE EXIT", game);
	}
	if (game->map[game->py][game->px] == 'P')
	{
		if ((mlx_image_to_window(game->mlx, game->image_player, game->px * X, \
		game->py * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE PLAYER", game);
	}
}


//
void	gui(t_game *game)
{
	loading_gui(game);
	print_map(game, game->map);
	print_objects(game);
}
