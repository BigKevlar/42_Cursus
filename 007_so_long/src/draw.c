/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:46:20 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/23 20:54:22 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	imgs2map_1(t_game *game, char **map, int c1, int c2)
{
	if (map[c1][c2] == '1')
	{
		mlx_image_to_window(game->mlx, game->image_wall, c2 * X, c1 * Y);
		if ((mlx_image_to_window(game->mlx, game->image_wall, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE MURO", game);
	}
	else if (map[c1][c2] == '0' || map[c1][c2] == 'C'
	|| map[c1][c2] == 'P' || map[c1][c2] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image_floor, c2 * X, c1 * Y);
		if ((mlx_image_to_window(game->mlx, game->image_floor, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE SUELO", game);
	}
}

//
static void	imgs2map_2(t_game *game, char **map, int c1, int c2)
{
	if (map[c1][c2] == 'P')
	{
		mlx_image_to_window(game->mlx, game->image_player, c2 * X, c1 * Y);
		if ((mlx_image_to_window(game->mlx, game->image_player, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE PLAYER", game);
	}
	else if (map[c1][c2] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image_coin, c2 * X, c1 * Y);
		if ((mlx_image_to_window(game->mlx, game->image_coin, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE COIN", game);
	}
	if (map[c1][c2] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image_exit_1, c2 * X, c1 * Y);
		if ((mlx_image_to_window(game->mlx, game->image_exit_1, \
		c2 * X, c1 * Y)) < 0)
			free_error("ERROR AL CARGAR IMAGEN DE EXIT", game);
	}
}

//
void	print_map(t_game *game, char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (c1 < game->rows)
	{
		c2 = 0;
		while (c2 < game->columns)
		{
			imgs2map_1(game, map, c1, c2);
			imgs2map_2(game, map, c1, c2);
			c2++;
		}
		c1++;
	}
}

//
void	gui(t_game *game)
{
	loading_gui(game);
	print_map(game, game->map);
	player_position(game);
	flood_fill(game, game->pos_x, game->pos_y);
	if (game->acc_coins != game->num_coins
		|| game->acc_exits != game->num_exits)
		free_error("ERROR DE ACCESIBILIDAD DE MONEDAS Y/O SALIDAS.", game);
}
