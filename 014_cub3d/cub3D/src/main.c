/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:33 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/10 18:39:04 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_game	g;

	g.ply = NULL;
	g.tex = NULL;
	g.img = NULL;
	g.ray = NULL;
	ft_memset(&g, '0', sizeof(t_game));
	if ((ac != 2) || (ac == 2 && av[1] == NULL))
	{
		ft_printf("ERROR! WRONG ARGUMENTS SINTAXIS...\n");
		exit (1);
	}
	parse_ext(av[1]);
	init_data_1(&g);
	init_data_2(&g);
	get_file(&g, av[1]);
	get_tex_color(&g);
	player_position(&g);
	check_map(&g);
	malloc_data(&g);
	check_inits(&g);
	run_game(&g);
	win_game(" [FIN DEL JUEGO] ", &g);
	return (0);
}
