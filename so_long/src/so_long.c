/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/04 15:54:21 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	parse_args(ac, av);
	return (0);
}

/*
int	main(void)
{
	void	*mlx_connection;

	mlx_connection = mlx_init(X, Y, "jmartos", true);
	mlx_loop(mlx_connection);
	return (0);
}
*/
