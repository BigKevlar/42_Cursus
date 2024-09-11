/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/11 14:19:50 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	draw_background(t_game *g)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			if (y < S_H / 2)
				mlx_put_pixel(g->img->background, x, y, g->ceiling_color);
			else
				mlx_put_pixel(g->img->background, x, y, g->floor_color);
			x++;
		}
		y++;
	}
}

/**/
void	run_game(t_game *g)
{
	g->ceiling_color = interpretate_color(g, g->color_c);
	g->floor_color = interpretate_color(g, g->color_f);
	g->mlx = mlx_init(S_W, S_H, "cub3D", true);
	g->img->background = mlx_new_image(g->mlx, S_W, S_H);
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
	mlx_image_to_window(g->mlx, g->img->background, 0, 0);
	draw_background(g);
	g->img->background->instances->z = 0;
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
