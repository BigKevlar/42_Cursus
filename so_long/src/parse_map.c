/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:50:28 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/05 19:59:04 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
Verificar si el mapa tiene todos 1 arriba, todos 1 abajo y en medio sea 1
el primero y el ultimo (recursividad???), vamos, tenemos que revisar primero
la primera y ultima linea de cada eje de coordenadas del mapa, y luego ya
las de en medio.
*/
void	get_map(t_game *game)
{
	int		fd;
	char	*line;
	int		c;

	c = 0;
	fd = open("maps/test_good_map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[c] = ft_strdup(line);
		line = get_next_line(fd);
		c++;
	}
	game->columns = c;
	close(fd);
}
