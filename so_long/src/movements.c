/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:56:37 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/23 13:30:57 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	up(t_game *game)
{
	action(game, game->pos_x - 1, game->pos_y);
}

static void	down(t_game *game)
{
	action(game, game->pos_x + 1, game->pos_y);
}

static void	left(t_game *game)
{
	action(game, game->pos_x, game->pos_y - 1);
}

static void	right(t_game *game)
{
	action(game, game->pos_x, game->pos_y + 1);
}

//
void	movement(mlx_key_data_t paramkey, t_game *game)
{
	if (paramkey.action != MLX_PRESS)
		return ;
	if (paramkey.key == MLX_KEY_W)
		up(game);
	else if (paramkey.key == MLX_KEY_S)
		down(game);
	else if (paramkey.key == MLX_KEY_A)
		left(game);
	else if (paramkey.key == MLX_KEY_D)
		right(game);
	else if (paramkey.key == MLX_KEY_ESCAPE)
	{
		erasing_gui(game);
		mlx_terminate(game->mlx);
		ft_charppfree(game->map);
		ft_charppfree(game->map_copy);
		free(game);
		exit (1);
	}
}
