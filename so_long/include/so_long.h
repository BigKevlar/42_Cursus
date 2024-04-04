/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:18:47 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/04 13:52:00 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libreria 42 jmartos- y la MiniLibX_42.
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Variables globales: tamaño de nuestra ventana de juego.
# define X 1024
# define Y 768

// Variables globales: colores.
# define BOLD		"\033[1m"
# define BLACK		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define END		"\033[0m"

// Esta estructura contendra el "codigo" del juego.
typedef struct s_map
{
	char		**map;
	char		buffer;
	int			x;
	int			y;
	int			linebreaks;
	int			player;
	int			coins;
	int			exit;
}				t_map;

// Esta estructura contendra el "decorado" del juego.
typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player_up;
	mlx_image_t	*player_down;
	mlx_image_t	*player_right;
	mlx_image_t	*player_left;
	mlx_image_t	*coin;
	mlx_image_t	*exit;
	mlx_image_t	*exit_open;
}				t_image;

// Estructura del juego en si mismo.
typedef struct s_game
{
	t_map		map_info;
	t_image		map_texture;
	int			index;
	int			moves;
	int			x_p;
	int			y_p;
	int			x;
	int			y;
	int			coin_cont;
	mlx_t		*mlx;
}				t_game;

void			open_map(t_game *info);

#endif
