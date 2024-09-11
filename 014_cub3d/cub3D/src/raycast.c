/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/11 14:17:00 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static bool	wall_hit(t_game *g, double x, double y, char flag)
{
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if (y < 0 || y >= g->map_rows || x < 0 || x >= g->map_columns)
		return (true);
	if (g->map[(int)y][(int)x] == '1')
	{
		if (flag == 'v')
			g->ray->door_v = false;
		else
			g->ray->door_h = false;
		return (true);
	}
	if (g->map[(int)y][(int)x] == '2')
	{
		if (flag == 'v')
			g->ray->door_v = true;
		else
			g->ray->door_h = true;
		return (true);
	}
	return (false);
}

/**/
static double	get_v_distance(t_game *g)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE * sign(cos(g->ray->angle));
	step_y = TILE_SIZE * tan(g->ray->angle) * sign(cos(g->ray->angle));
	x_pos = floor(g->ply->x / TILE_SIZE) * TILE_SIZE;
	if (cos(g->ray->angle) >= 0)
		x_pos += TILE_SIZE;
	y_pos = g->ply->y + (x_pos - g->ply->x) * tan(g->ray->angle);
	while (!wall_hit(g, x_pos + sign(cos(g->ray->angle)), y_pos, 'v'))
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	g->ray->x = x_pos;
	g->ray->y = y_pos;
	return (sqrt(pow(x_pos - g->ply->x, 2) + pow(y_pos - g->ply->y, 2)));
}

/**/
static double	get_h_distance(t_game *g)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE / tan(g->ray->angle) * sign(sin(g->ray->angle));
	step_y = TILE_SIZE * sign(sin(g->ray->angle));
	y_pos = floor(g->ply->y / TILE_SIZE) * TILE_SIZE;
	if (sin(g->ray->angle) >= 0)
		y_pos += TILE_SIZE;
	x_pos = g->ply->x + (y_pos - g->ply->y) / tan(g->ray->angle);
	while (!wall_hit(g, x_pos, y_pos + sign(sin(g->ray->angle)), 'h'))
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	g->ray->x2 = x_pos;
	g->ray->y2 = y_pos;
	return (sqrt(pow(x_pos - g->ply->x, 2) + pow(y_pos - g->ply->y, 2)));
}

void	casting(t_game *g, double increment, int i)
{
	double	v_distance;
	double	h_distance;

	while (i < S_W)
	{
		v_distance = get_v_distance(g);
		h_distance = get_h_distance(g);
		if (v_distance <= h_distance)
		{
			g->ray->distance = v_distance;
			get_v_surface(g);
		}
		else
		{
			g->ray->distance = h_distance;
			g->ray->door_v = g->ray->door_h;
			get_h_surface(g);
			g->ray->x = g->ray->x2;
			g->ray->y = g->ray->y2;
		}
		g->ray->distance *= cos(fabs(g->ray->angle - g->ply->angle));
		render(g, i);
		i++;
		g->ray->angle = g->ray->angle + increment;
	}
}

/**/
void	raycast(void *param)
{
	t_game	*g;
	double	increment;
	int		i;

	g = param;
	increment = FOV / S_W;
	i = 0;
	g->ray->angle = g->ply->angle - (FOV / 2);
	ft_clear_window(g);
	casting(g, increment, i);
	g->img->window->instances->z = 1;
}
