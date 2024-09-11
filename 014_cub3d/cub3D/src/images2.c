/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:35:29 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 19:31:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	init_textures(t_game *g)
{
	g->tex->n = NULL;
	g->tex->s = NULL;
	g->tex->e = NULL;
	g->tex->w = NULL;
	g->tex->door = NULL;
	g->tex->n = mlx_load_png(g->texture_no);
	g->tex->s = mlx_load_png(g->texture_so);
	g->tex->e = mlx_load_png(g->texture_ea);
	g->tex->w = mlx_load_png(g->texture_we);
	g->tex->door = mlx_load_png("tex/Door.png");
	if (!g->tex->n || !g->tex->s || !g->tex->e || !g->tex->w || !g->tex->door)
	{
		free_error("ERROR! LOADING TEXTURES FAIL...\n", g);
	}
}

/**/
int	check_comas(char *rgb)
{
	int	comas;
	int	i;

	i = 0;
	comas = 0;
	while (rgb[i])
	{
		if (rgb[i] == ',')
			comas++;
		i++;
	}
	if (comas == 2)
		return (1);
	else
		return (0);
}

/**/
static uint32_t	rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	color;

	color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (color);
}

/**/
uint32_t	interpretate_color(t_game *g, char *color)
{
	char	**rgb;
	int		r;
	int		gr;
	int		b;
	int		i;

	r = -1;
	gr = -1;
	b = -1;
	if (!check_comas(color))
		free_error("ERROR! COLORS FAIL...\n", g);
	rgb = ft_split(color, ',');
	if (ft_isdigit_str(rgb[0]) && rgb[0])
		r = ft_atoi(rgb[0]);
	if (ft_isdigit_str(rgb[1]))
		gr = ft_atoi(rgb[1]);
	if (ft_isdigit_str(rgb[2]))
		b = ft_atoi(rgb[2]);
	i = 0;
	while (rgb[i])
		free (rgb[i++]);
	free (rgb);
	if (r > 255 || gr > 255 || b > 255 || r < 0 || gr < 0 || b < 0)
		free_error("ERROR! RGB FAIL...", g);
	return (rgb_to_uint32(r, gr, b));
}
