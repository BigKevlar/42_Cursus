/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:53:22 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/11 14:08:23 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	rotate_player(t_game *g)
{
	if (g->ply->rotate == 1)
	{
		g->ply->angle += ROTATESPEED;
		if (g->ply->angle > 2 * M_PI)
			g->ply->angle -= 2 * M_PI;
	}
	else if (g->ply->rotate == -1)
	{
		g->ply->angle -= ROTATESPEED;
		if (g->ply->angle < 0)
			g->ply->angle += 2 * M_PI;
	}
}

/**/
static void	move_player(t_game *g, double move_x, double move_y)
{
	int		new_x;
	int		new_y;

	new_x = 0;
	new_y = 0;
	new_x = roundf(g->ply->x + move_x);
	new_y = roundf(g->ply->y + move_y);
	if (new_x >= 0 && new_x <= g->map_columns * TILE_SIZE)
		g->ply->x = new_x;
	if (new_y >= 0 && new_y <= g->map_rows * TILE_SIZE)
		g->ply->y = new_y;
}

/**/
void	ft_game_hook(void *param)
{
	t_game	*g;
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	g = param;
	rotate_player(g);
	if (g->ply->move_d == true)
	{
		move_x += -sin(g->ply->angle) * MOVESPEED;
		move_y += cos(g->ply->angle) * MOVESPEED;
	}
	if (g->ply->move_a == true)
	{
		move_x += sin(g->ply->angle) * MOVESPEED;
		move_y += -cos(g->ply->angle) * MOVESPEED;
	}
	if (g->ply->move_w)
	{
		move_x += cos(g->ply->angle) * MOVESPEED * g->ply->move_w;
		move_y += sin(g->ply->angle) * MOVESPEED * g->ply->move_w;
	}
	move_player(g, move_x, move_y);
}

/**/
void	ft_key_release(mlx_key_data_t keydata, t_game *g)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		g->ply->move_d = false;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		g->ply->move_a = false;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		g->ply->move_w = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		g->ply->move_w = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		g->ply->rotate = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		g->ply->rotate = 0;
}

/**/
void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		g->ply->move_a = true;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		g->ply->move_d = true;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		g->ply->move_w = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		g->ply->move_w = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		g->ply->rotate = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		g->ply->rotate = 1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g->mlx);
	ft_key_release(keydata, g);
}
