/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:06:18 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/22 14:20:24 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	win_game(t_game *game)
{
	ft_printf("ENHORABUENA, HAS GANADO EN %d PASOS. ==", game->moves_counter);
	ft_charppfree(game->map);
	ft_charppfree(game->map_copy);
	free(game);
	exit (1);
}
