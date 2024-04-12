/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/12 18:49:14 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		c;

	(void)ac;
	c = 0;
	game = get_map(av[1]);
	check_ext(av[1], game);
	while (game->map[c] != NULL)
		ft_printf("%s", game->map[c++]);
	free_error("", game);
	return (0);
}
