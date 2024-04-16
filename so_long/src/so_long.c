/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/16 19:44:44 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	//int		c;

	//c = 0;
	game = get_map(av[1]);
	make_struct(game);
	parse_map(game);
	//ft_printf("ROWS: %i\n", game->rows);
	//ft_printf("COLUMNS: %i\n", game->columns);
	//while (game->map[c])
		//ft_printf("%s", game->map[c++]);
	//ft_printf("\n");
	parse_args(ac, av);
	parse_ext(av[1], game);
	check_walls(game);
	init_game(game);
	free_error("", game);
	return (0);
}
