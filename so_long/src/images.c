/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:01:12 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/17 23:01:11 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
void	loading_gui(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./images/floor.png");
	game->image_floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/wall.png");
	game->image_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/player.png");
	game->image_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/coin.png");
	game->image_coin = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/exit_1.png");
	game->image_exit_1 = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/exit_2.png");
	game->image_exit_2 = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
