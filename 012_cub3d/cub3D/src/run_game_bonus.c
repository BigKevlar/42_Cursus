/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/10 20:58:39 by jmartos-         ###   ########.fr       */
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
void	ft_mouse_hook(void *param)
{
	t_game	*g;

	g = param;
	mlx_get_mouse_pos(g->mlx, &g->ply->mouse_x, &g->ply->mouse_y);
	g->ply->angle += ((float)(g->ply->mouse_x - (S_W / 2)) / (S_H / 2) * 0.4);
	mlx_set_mouse_pos(g->mlx, (S_W / 2), (S_H / 2));
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
	load_torch_textures(g);
	draw_background(g);
	g->img->background->instances->z = 0;
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_set_cursor_mode(g->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(g->mlx, (void *)ft_mouse_hook, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
