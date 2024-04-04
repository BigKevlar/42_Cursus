/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/04 00:35:43 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	void	*mlx_connection;

	mlx_connection = mlx_init(X, Y, "jmartos", true);
	mlx_loop(mlx_connection);
	return (0);
}
