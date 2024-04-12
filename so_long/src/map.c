/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:50:28 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/12 19:39:13 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// str_join + split ???
t_game	*get_map(char *map)
{
	int		fd;
	char	*line;
	int		c;
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_error("ERROR AL ABRIR MAPA", game);
	line = get_next_line(fd);
	c = 0;
	game->map = ft_calloc(7 + 1, sizeof(char *));
	while (line != NULL)
	{
		game->map[c] = line;
		line = get_next_line(fd);
		c++;
	}
	game->rows = c;
	game->columns = ft_strlen(game->map[0]);
	close(fd);
	return (game);
}

/*
int	check_walls(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (game->map[c1])
		c1++;
	game->rows = c1;
	c1 = 0;
	while (game->map[c1])
	{
		c2 = 0;
		if (c1 == 0 || c1 == game->rows - 1)
		{
			while (c2 < game->columns)
			{
				if (game->map[c1][c2++] != '1')
					return (0);
			}
		}
		else if (game->map[c1][0] != '1'
		||game->map[c1][game->columns - 1] != '1')
			return (0);
		c1++;
	}
	return (1);
}
*/
