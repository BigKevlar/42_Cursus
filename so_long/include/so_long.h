/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:18:47 by jmartos           #+#    #+#             */
/*   Updated: 2024/04/16 13:46:36 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libreria 42 jmartos- y la MiniLibX_42.
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Variables estaticas: tamaño de nuestra ventana de juego.
# define X 1024
# define Y 768

// Variables estaticas: colores.
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

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				rows;
	int				columns;
	int				player;
	int				coin;
	int				exit;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_player_up;
	mlx_image_t		*image_player_down;
	mlx_image_t		*image_player_right;
	mlx_image_t		*image_player_left;
	mlx_image_t		*image_coin;
	mlx_image_t		*image_exit_close;
	mlx_image_t		*image_exit_open;
	mlx_image_t		*image_background;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_coin;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_background;
}					t_game;

void	free_error(char *msg, t_game *game);
void	make_struct(t_game *game);
t_game	*get_map(char *map);
void	parse_map(t_game *game);
void	parse_ext(char *av, t_game *game);
void	parse_args(int ac, char **av);
void	check_walls(t_game *game);
int32_t	init_game(t_game *game);

#endif