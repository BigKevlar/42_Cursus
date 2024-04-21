/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:44:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/22 00:25:29 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	action(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] != '1')
	{
		if (game->map[new_x][new_y] == 'C')
			game->coins_counter++;
		else if (game->map[new_x][new_y] == 'E')
		{
			if (game->coins_counter == game->num_coins)
				free_game(game);
			else if (game->map[new_x][new_y] == 'E'
			&& game->coins_counter != game->num_coins)
				return ;
		}
		game->map[game->pos_x][game->pos_y] = '0';
		game->map[new_x][new_y] = 'P';
		game->pos_x = new_x;
		game->pos_y = new_y;
		print_map(game, game->map);
		game->moves_counter++;
		ft_printf("Pasos: %d -- ", game->moves_counter);
		ft_printf("Coins: %d\n", game->coins_counter);
	}
}
