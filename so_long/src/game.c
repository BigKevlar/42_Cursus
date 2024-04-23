/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:13:48 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/23 20:34:29 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_columns(char *map)
{
	int		fd;
	int		columns;
	char	*line;

	columns = 1;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		columns++;
	}
	close(fd);
	return (columns);
}

//
void	make_struct(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->map_copy = NULL;
	game->player = 'P';
	game->coin = 'C';
	game->exit = 'E';
	game->image_floor = NULL;
	game->image_wall = NULL;
	game->image_player = NULL;
	game->image_coin = NULL;
	game->image_exit_1 = NULL;
	game->image_exit_2 = NULL;
}

//
int32_t	init_game(t_game *game)
{
	game->mlx = mlx_init(64 * game->columns, 64 * game->rows, "so_long", false);
	if (!game->mlx)
		free_error("ERROR AL INICIAR JUEGO", game);
	gui(game);
	ft_printf("Pasos: %d -- ", game->moves_counter);
	ft_printf("Coins: %d\n", game->coins_counter);
	mlx_key_hook(game->mlx, (mlx_keyfunc)movement, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
