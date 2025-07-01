/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:30:16 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/09 15:18:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	load_torch_textures(t_game *g)
{
	int	torch_x;
	int	torch_y;

	torch_x = ((3 * S_W) / 4) - (400 / 2);
	torch_y = S_H - 400 - 20;
	g->t_tex00 = mlx_load_png("tex/torch_frames/frame00.png");
	g->t_tex01 = mlx_load_png("tex/torch_frames/frame01.png");
	g->t_tex02 = mlx_load_png("tex/torch_frames/frame02.png");
	g->t_tex03 = mlx_load_png("tex/torch_frames/frame03.png");
	g->t_tex04 = mlx_load_png("tex/torch_frames/frame04.png");
	g->t_tex05 = mlx_load_png("tex/torch_frames/frame05.png");
	g->t_tex06 = mlx_load_png("tex/torch_frames/frame06.png");
	g->t_tex07 = mlx_load_png("tex/torch_frames/frame07.png");
	if (!(g->t_tex00 && g->t_tex01 && g->t_tex02
			&& g->t_tex03 && g->t_tex04 && g->t_tex05
			&& g->t_tex06 && g->t_tex07))
		free_error("ERROR al convertir PNG en texturas!\n", g);
	g->torch_img = mlx_new_image(g->mlx, g->t_tex00->width, g->t_tex00->height);
	mlx_image_to_window(g->mlx, g->torch_img, torch_x, torch_y);
	g->torch_img->instances->z = 2;
}

/**/
void	draw_torch(t_game *g)
{
	if (g->actual_torch_frame == 0)
		g->torch_tex = g->t_tex00;
	else if (g->actual_torch_frame == 1)
		g->torch_tex = g->t_tex01;
	else if (g->actual_torch_frame == 2)
		g->torch_tex = g->t_tex02;
	else if (g->actual_torch_frame == 3)
		g->torch_tex = g->t_tex03;
	else if (g->actual_torch_frame == 4)
		g->torch_tex = g->t_tex04;
	else if (g->actual_torch_frame == 5)
		g->torch_tex = g->t_tex05;
	else if (g->actual_torch_frame == 6)
		g->torch_tex = g->t_tex06;
	else if (g->actual_torch_frame == 7)
		g->torch_tex = g->t_tex07;
	mlx_draw_texture(g->torch_img, g->torch_tex, 0, 0);
	g->torch_frame_counter++;
	if (g->torch_frame_counter >= g->torch_animation_speed)
	{
		g->actual_torch_frame = (g->actual_torch_frame + 1) % 8;
		g->torch_frame_counter = 0;
	}
}
