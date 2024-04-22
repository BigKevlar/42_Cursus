/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/22 16:11:29 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
void	player_position(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (game->map_copy[c1])
	{
		c2 = 0;
		while (game->map_copy[c1][c2])
		{
			if (game->map_copy[c1][c2] == 'P')
			{
				game->pos_x = c1;
				game->pos_y = c2;
				return ;
			}
			c2++;
		}
		c1++;
	}
}

//
void	flood_fill(t_game *game, int x, int y)
{
	int	acc_coins;
	int	acc_exits;

	acc_coins = 0;
	acc_exits = 0;
	if (game->map_copy[x][y] == 'C')
	{
		acc_coins++;
		ft_printf("map_copy[x][y]: %c\n -- ", game->map_copy[x][y]);
	}
	if (game->map_copy[x][y] == 'E')
		acc_exits++;
	if (x < 0 || y < 0 || x >= game->columns || y >= game->rows
		|| game->map_copy[x][y] == '1' || game->map_copy[x][y] == 'x')
		return ;
	if (game->map_copy[x][y] == '0' || game->map_copy[x][y] == 'P')
	{
		game->map_copy[x][y] = 'x';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y - 1);
		flood_fill(game, x, y + 1);
	}
	if (acc_coins != game->num_coins || acc_exits != game->num_exits)
		free_error("ERROR EN FLOOD_FILL.", game);
}
