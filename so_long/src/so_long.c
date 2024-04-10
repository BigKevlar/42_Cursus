/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/10 19:44:35 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;

	(void)ac;

	i = 0;
	game = ft_calloc(1, sizeof(t_game));
	get_map(av[1], game);
	check_ext(av[1]);
	/*check_walls(game);*/
	while (i < game->columns)
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
	ft_printf("\n");
	free(game);
	return (0);
}
