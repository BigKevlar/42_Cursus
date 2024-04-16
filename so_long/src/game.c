/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:13:48 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/16 13:46:28 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
void	make_struct(t_game *game)
{
	game->player = 'P';
	game->coin = 'C';
	game->exit = 'E';
	game->image_floor = NULL;
	game->image_wall = NULL;
	game->image_player_up = NULL;
	game->image_player_down = NULL;
	game->image_player_right = NULL;
	game->image_player_left = NULL;
	game->image_coin = NULL;
	game->image_exit_close = NULL;
	game->image_exit_open = NULL;
	game->image_background = NULL;
	game->texture_floor = NULL;
	game->texture_wall = NULL;
	game->texture_player = NULL;
	game->texture_coin = NULL;
	game->texture_exit = NULL;
	game->texture_background = NULL;
}

//
int32_t	init_game(t_game *game)
{
	game->mlx = mlx_init(game->rows * X, game->columns * Y, "so_long", false);
	if (!game->mlx)
		free_error("ERROR AL INICIAR JUEGO", game);
	//accion_player(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
