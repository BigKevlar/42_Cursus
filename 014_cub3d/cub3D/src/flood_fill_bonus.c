/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/09/11 13:32:20 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	player_position(t_game *g)
{
	int	c1;
	int	c2;
	int	player;

	player = 0;
	c1 = 0;
	while (g->map[++c1])
	{
		c2 = 0;
		while (g->map[c1][++c2])
		{
			if (g->map[c1][c2] == 'N' || g->map[c1][c2] == 'S'
				|| g->map[c1][c2] == 'E' || g->map[c1][c2] == 'W')
			{
				player++;
				g->player_y = c1;
				g->player_x = c2;
				g->player_orientation = g->map[g->player_y][g->player_x];
				g->map[g->player_y][g->player_x] = '0';
			}
		}
	}
	if (player != 1)
		free_error("ERROR! PLAYERS FAIL...", g);
}

/**/
void	map_orientation(t_game *g)
{
	if (g->player_orientation == 'N')
		g->ply->angle = 3 * (M_PI / 2);
	else if (g->player_orientation == 'S')
		g->ply->angle = M_PI / 2;
	else if (g->player_orientation == 'E')
		g->ply->angle = 0;
	else if (g->player_orientation == 'S')
		g->ply->angle = M_PI;
}

/**/
double	get_colum(t_game *g)
{
	double	colum;

	colum = 0;
	if (g->ray->side == SOUTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum = g->ray->x;
	}
	else if (g->ray->side == NORTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum = TILE_SIZE - g->ray->x;
	}
	else if (g->ray->side == WEST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = TILE_SIZE - g->ray->y;
	}
	else if (g->ray->side == EAST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = g->ray->y;
	}
	return ((colum * g->ray->tex->width));
}

/**/
static int	check_zero(t_game *g, int y, int x)
{
	if (x <= 0 || y <= 0
		|| x >= g->map_columns || y >= g->map_rows - 1)
		return (0);
	if (!g->map[y + 1][x]
		|| g->map[y + 1][x] == ' '
		|| g->map[y - 1][x] == ' '
		|| !g->map[y][x + 1]
		|| g->map[y][x + 1] == ' '
		|| g->map[y][x - 1] == ' ')
		return (0);
	return (1);
}

/**/
void	check_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] != '0' && g->map[y][x] != '1'
				&& g->map[y][x] != ' ' && g->map[y][x] != '2')
				free_error("ERROR! MAP HAS INVALID CHARACTERS...", g);
			if (g->map[y][x] == '0' || g->map[y][x] == '2')
			{
				if (!check_zero(g, y, x))
					free_error("ERROR! MAP HAS OPEN AREA...", g);
			}
			x++;
		}
		y++;
	}
}
