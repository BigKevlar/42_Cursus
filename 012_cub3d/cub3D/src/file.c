/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 19:35:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	file_size(t_game *g, char *file)
{
	int		fd;
	char	*line;

	g->file_size = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T EXIST...", g);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		g->file_size++;
	}
	close(fd);
}

/**/
void	get_file(t_game *g, char *file)
{
	int		fd;
	char	*line;
	int		i;

	file_size(g, file);
	if (g->file_size <= 1)
		free_error("ERROR! FILE EMPTY...", g);
	i = 0;
	g->file = ft_calloc(g->file_size + 1, sizeof(char *));
	if (!g->file)
		free_error("ERROR! FILE MEMORY ALLOCATION FAILED...", g);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T OPEN...", g);
	line = get_next_line(fd);
	while (line != NULL)
	{
		g->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

/**/
void	get_tex_color(t_game *g)
{
	int	i;

	i = 0;
	while (g->file[i][0] == '\n')
		i++;
	if (g->file[i][0] == 'F' || g->file[i][0] == 'C')
	{
		i = get_colors(g, i);
		i = get_textures(g, i);
	}
	else
	{
		i = get_textures(g, i);
		i = get_colors(g, i);
	}
	get_map(g, i);
}

void	tokenizing(t_game *g, char **texture, char **tokens, int *flag)
{
	if (*texture || tokens[2])
	{
		ft_strd_free(tokens);
		free_error("ERROR! FORMAT ERROR IN TEXTURE OR COLOR...", g);
	}
	*texture = ft_strdup(tokens[1]);
	*flag += 1;
}
