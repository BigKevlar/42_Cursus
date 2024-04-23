/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:44:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/23 12:32:49 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	action(t_game *game, int new_x, int new_y)
{
	//ft_printf("new_X del player: %i\n", new_x);
	//ft_printf("new_Y del player: %i\n", new_y);
	if (game->map[new_x][new_y] != '1')
	{
		if (game->map[new_x][new_y] == 'C')
			game->coins_counter++;
		else if (game->map[new_x][new_y] == 'E')
		{
			if (game->coins_counter == game->num_coins)
				win_game(game);
			else if (game->map[new_x][new_y] == 'E'
			&& game->coins_counter != game->num_coins)
				return ;
		}
		game->map[game->pos_x][game->pos_y] = '0';
		game->map[new_x][new_y] = 'P';
		game->pos_x = new_x;
		game->pos_y = new_y;
		game->moves_counter++;
		print_map(game, game->map);
		ft_printf("Pasos: %d -- ", game->moves_counter);
		ft_printf("Coins: %d\n", game->coins_counter);
	}
}
