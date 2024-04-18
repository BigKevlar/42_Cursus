/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:13:48 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/18 16:18:47 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	make_struct(t_game *game)
{
	game->mlx = NULL;
	game->player = 'P';
	game->coin = 'C';
	game->exit = 'E';
	game->image_floor = NULL;
	game->image_wall = NULL;
	game->image_player = NULL;
	game->image_coin = NULL;
	game->image_exit_1 = NULL;
	game->image_exit_2 = NULL;
	game->texture_floor = NULL;
	game->texture_wall = NULL;
	game->texture_player = NULL;
	game->texture_coin = NULL;
	game->texture_exit_1 = NULL;
	game->texture_exit_2 = NULL;
	game->px = 0;
	game->py = 0;
	game->cx = 0;
	game->cy = 0;
	game->ex = 0;
	game->ey = 0;
}

//
int32_t	init_game(t_game *game)
{
	make_struct(game);
	game->mlx = mlx_init(64 *game->columns, 64 * game->rows, "so_long", false);
	if (!game->mlx)
		free_error("ERROR AL INICIAR JUEGO", game);
	gui(game);
	//movements(game);
	mlx_loop(game->mlx);
	//mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
