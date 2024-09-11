/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:50:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/11 14:22:31 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	continue_free(t_game *g)
{
	free (g->texture_no);
	free (g->texture_so);
	free (g->texture_we);
	free (g->texture_ea);
	exit (1);
}

/**/
void	free_error(char *msg, t_game *g)
{
	ft_printf("%s\n", msg);
	if (g == NULL)
		exit (1);
	if (g != NULL)
	{
		ft_strd_free(g->file);
		ft_strd_free(g->map);
		free(g->ply);
		free(g->img);
		free(g->ray);
		if (g->tex && g->tex->n)
			mlx_delete_texture(g->tex->n);
		if (g->tex && g->tex->s)
			mlx_delete_texture(g->tex->s);
		if (g->tex && g->tex->e)
			mlx_delete_texture(g->tex->e);
		if (g->tex && g->tex->w)
			mlx_delete_texture(g->tex->w);
		if (g->tex && g->tex->door)
			mlx_delete_texture(g->tex->door);
		free(g->tex);
		free (g->color_c);
		free (g->color_f);
		continue_free(g);
	}
}

/**/
static void	delete_textures(t_game *g)
{
	mlx_delete_texture(g->tex->n);
	mlx_delete_texture(g->tex->s);
	mlx_delete_texture(g->tex->e);
	mlx_delete_texture(g->tex->w);
	mlx_delete_texture(g->tex->door);
}

/**/
void	win_game(char *msg, t_game *g)
{
	ft_printf("%s\n", msg);
	ft_strd_free(g->file);
	free(g->texture_no);
	free(g->texture_so);
	free(g->texture_we);
	free(g->texture_ea);
	free(g->color_c);
	free(g->color_f);
	ft_strd_free(g->map);
	delete_textures(g);
	free(g->tex);
	free(g->img);
	free(g->ray);
	free(g->ply);
	mlx_terminate(g->mlx);
}

/**/
int	sign(double n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}
