/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:49:34 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/11 13:41:47 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	init_player(t_game *g)
{
	g->ply->move_a = false;
	g->ply->move_d = false;
	g->ply->move_w = 0;
	g->ply->rotate = 0;
	g->ply->x = g->player_x * TILE_SIZE + (TILE_SIZE / 2);
	g->ply->y = g->player_y * TILE_SIZE + (TILE_SIZE / 2);
	g->ratio = S_H * TILE_SIZE;
}

/**/
void	malloc_data(t_game *g) //cuidado con esta
{
	g->ply = malloc(sizeof(t_player));
	g->ray = malloc(sizeof(t_ray));
	g->tex = malloc(sizeof(t_tex));
	g->img = malloc(sizeof(t_img));
	map_orientation(g);
	init_textures(g);
	init_player(g);
}

/**/
void	init_data_1(t_game *g)
{
	g->mlx = NULL;
	g->file = NULL;
	g->file_size = 0;
	g->texture_no = NULL;
	g->texture_so = NULL;
	g->texture_we = NULL;
	g->texture_ea = NULL;
	g->color_f = NULL;
	g->color_c = NULL;
	g->map = NULL;
	g->map_rows = 0;
	g->map_columns = 0;
	g->player_x = 0;
	g->player_y = 0;
	g->player_orientation = 0;
}

/**/
void	init_data_2(t_game *g)
{
	g->t_tex00 = NULL;
	g->t_tex01 = NULL;
	g->t_tex02 = NULL;
	g->t_tex03 = NULL;
	g->t_tex04 = NULL;
	g->t_tex05 = NULL;
	g->t_tex06 = NULL;
	g->t_tex07 = NULL;
	g->torch_tex = NULL;
	g->t_image00 = NULL;
	g->t_image01 = NULL;
	g->t_image02 = NULL;
	g->t_image03 = NULL;
	g->t_image04 = NULL;
	g->t_image05 = NULL;
	g->t_image06 = NULL;
	g->t_image07 = NULL;
	g->torch_img = NULL;
	g->torch_animation_speed = 6;
	g->actual_torch_frame = 0;
	g->torch_frame_counter = 0;
	g->tex = NULL;
	g->img = NULL;
	g->ray = NULL;
	g->ply = NULL;
}

/**/
void	check_inits(t_game *g)
{
	if (!g->file
		|| !g->texture_no || !g->texture_so || !g->texture_we || !g->texture_ea
		|| !g->color_f || !g->color_c || !g->map
		|| !g->tex || !g->img || !g->ray || !g->ply)
	{
		ft_printf("ERROR! SOMETHINGS WRONG WITH DATAS, PLEASE TRY AGAIN...\n");
		ft_strd_free(g->file);
		free(g->texture_no);
		free(g->texture_so);
		free(g->texture_we);
		free(g->texture_ea);
		free(g->color_f);
		free(g->color_c);
		ft_strd_free(g->map);
		free(g->tex);
		free(g->img);
		free(g->ray);
		free(g->ply);
	}
}
