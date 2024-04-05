/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/05 19:54:21 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_game	*game;
	int		i;

	i = 0;
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(char **));
	get_map(game);
	while (i < game->columns)
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
