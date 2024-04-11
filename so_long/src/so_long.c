/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/11 16:00:59 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	(void)ac;
	ft_printf("%s\n", "breakpoint_1");
	game = get_map(av[1]);
	ft_printf("%s\n", "breakpoint_2");
	check_ext(av[1]);
	ft_printf("%s\n", "breakpoint_3");
	free_error("FIN", game);
	return (0);
}
