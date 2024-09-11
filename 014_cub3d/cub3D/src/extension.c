/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:39:22 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 21:54:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static char	*get_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	return (ext);
}

/**/
void	parse_ext(char *av)
{
	char	*ext;

	ext = get_ext(av);
	if (ext == NULL || ft_strncmp(ext, ".cub", 5) != 0)
	{
		ft_printf("ERROR! WRONG FILE EXTENSION...\n");
		exit (1);
	}
}
