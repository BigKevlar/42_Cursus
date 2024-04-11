/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:50:28 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/11 14:50:14 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
void	get_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	int		c;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_error("ERROR AL ABRIR MAPA", game);
	line = get_next_line(fd);
	if (line == NULL)
		free_error("ERROR AL INSERTAR LINEA", game);
	c = 0;
	while (line != NULL)
	{
		ft_printf("%s", line);
		game->map = ft_calloc(1, sizeof(char **));
		game->map[c] = ft_strdup(line);
		if (game->map[c] == NULL)
			free_error("ERROR ALOJANDO MEMORIA", game);
		free(line);
		line = get_next_line(fd);
		c++;
	}
	free(line);
	game->columns = c;
	close(fd);
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
