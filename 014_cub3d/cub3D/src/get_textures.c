/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:53:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 19:20:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	token_texture(t_game *g, char **tokens, int *flag)
{
	if (!tokens)
		free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
	if (tokens[0] && ft_strcmp(tokens[0], "NO") == 0 && tokens[1])
		tokenizing(g, &g->texture_no, tokens, flag);
	else if (tokens[0] && ft_strcmp(tokens[0], "SO") == 0 && tokens[1])
		tokenizing(g, &g->texture_so, tokens, flag);
	else if (tokens[0] && ft_strcmp(tokens[0], "WE") == 0 && tokens[1])
		tokenizing(g, &g->texture_we, tokens, flag);
	else if (tokens[0] && ft_strcmp(tokens[0], "EA") == 0 && tokens[1])
		tokenizing(g, &g->texture_ea, tokens, flag);
	else
	{
		ft_strd_free(tokens);
		free_error("ERROR! TEXTURES FAIL...", g);
	}
}

/**/
int	get_textures(t_game *g, int i)
{
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i] && g->file[i][0] == '\n')
		i++;
	if (!g->file[i])
		free_error("ERROR! TEXTURES EMPTY", g);
	while (g->file[i] && flag != 4)
	{
		line = ft_strtrim(g->file[i++], " \n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		token_texture(g, tokens, &flag);
		ft_strd_free(tokens);
	}
	if (!g->texture_no || !g->texture_so || !g->texture_we || !g->texture_ea)
		free_error("ERROR! MISSING SOME TEXTURE PATH...", g);
	return (i);
}
