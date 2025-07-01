/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:53:23 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 19:20:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	token_colors(t_game *g, char **tokens, int *flag)
{
	if (!tokens)
		free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
	if (tokens[0] && ft_strcmp(tokens[0], "C") == 0 && tokens[1])
		tokenizing(g, &g->color_c, tokens, flag);
	else if (tokens[0] && ft_strcmp(tokens[0], "F") == 0 && tokens[1])
		tokenizing(g, &g->color_f, tokens, flag);
	else
	{
		ft_strd_free(tokens);
		free_error("ERROR! COLORS FAIL...", g);
	}
}

/**/
int	get_colors(t_game *g, int i)
{
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i] && g->file[i][0] == '\n')
		i++;
	if (!g->file[i])
		free_error("ERROR! COLORS EMPTY", g);
	while (g->file[i] && flag != 2)
	{
		line = ft_strtrim(g->file[i++], " \n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		token_colors(g, tokens, &flag);
		ft_strd_free(tokens);
	}
	if (!g->color_c || !g->color_f)
		free_error("ERROR! MISSING SOME COLORS PATH...", g);
	return (i);
}
