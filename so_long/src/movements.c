/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:56:37 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/21 00:32:10 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
//
void	up(t_game *game)
{	
	if (game->map[game->move_x - 1][game->move_y] != '1'
		&& (game->map[game->move_x - 1][game->move_y] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x - 1][game->move_y] == 'C')
			game->count_collect--;
		if (game->map[game->move_x - 1][game->move_y] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x - 1][game->move_y] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

//
void	down(t_game *game)
{
	if (game->map[game->move_x + 1][game->move_y] != '1'
		&& (game->map[game->move_x + 1][game->move_y] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x + 1][game->move_y] == 'C')
			game->count_collect--;
		if (game->map[game->move_x + 1][game->move_y] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x + 1][game->move_y] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

//
void	left(t_game *game)
{
	if (game->map[game->move_x][game->move_y - 1] != '1'
		&& (game->map[game->move_x][game->move_y - 1] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x][game->move_y - 1] == 'C')
			game->count_collect--;
		if (game->map[game->move_x][game->move_y - 1] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x][game->move_y - 1] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

//
void	right(t_game *game)
{
	if (game->map[game->move_x][game->move_y + 1] != '1'
		&& (game->map[game->move_x][game->move_y + 1] != 'E'
		|| game->count_collect == 0))
	{
		game->map[game->move_x][game->move_y] = '0';
		if (game->map[game->move_x][game->move_y + 1] == 'C')
			game->count_collect--;
		if (game->map[game->move_x][game->move_y + 1] == 'E'
			&& game->count_collect == 0)
			exit_good(game);
		else
		{
			game->map[game->move_x][game->move_y + 1] = 'P';
			draw_map(game->mlx, game);
			game->count_moves++;
			ft_printf("\nMoves: %d", game->count_moves);
		}
	}
}

//
void	movements(mlx_key_data_t paramkey, t_game *game)
{
	if ((paramkey.key == MLX_KEY_W || paramkey.key == MLX_KEY_UP)
		&& paramkey.action == MLX_PRESS)
		up(game);
	if ((paramkey.key == MLX_KEY_S || paramkey.key == MLX_KEY_DOWN)
		&& paramkey.action == MLX_PRESS)
		down(game);
	if ((paramkey.key == MLX_KEY_A || paramkey.key == MLX_KEY_LEFT)
		&& paramkey.action == MLX_PRESS)
		left(game);
	if ((paramkey.key == MLX_KEY_D || paramkey.key == MLX_KEY_RIGHT)
		&& paramkey.action == MLX_PRESS)
		right(game);
	if ((paramkey.key == MLX_KEY_ESCAPE || paramkey.key == MLX_KEY_Q)
		&& paramkey.action == MLX_PRESS)
		free_game(game);
}
*/