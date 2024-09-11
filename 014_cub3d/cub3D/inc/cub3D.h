/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:17 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/10 20:46:47 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>
# include <unistd.h>

# define S_W 1024
# define S_H 768
# define MOVESPEED 2
# define ROTATESPEED 0.05
# define TILE_SIZE 32
# define FOV 1.15192

typedef struct s_tex
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
	mlx_texture_t	*door;
}	t_tex;

typedef enum e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_side;

typedef struct s_img
{
	mlx_image_t	*window;
	mlx_image_t	*minimap;
	mlx_image_t	*background;
}	t_img;

typedef struct s_ray
{
	double			angle;
	double			x;
	double			y;
	double			x2;
	double			y2;
	mlx_texture_t	*tex;
	double			distance;
	t_side			side;
	bool			door_h;
	bool			door_v;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	int		move_w;
	bool	move_a;
	bool	move_d;
	int		rotate;
	int		mouse_x;
	int		mouse_y;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**file;
	int				file_size;
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	char			*color_f;
	char			*color_c;
	char			**map;
	int				map_rows;
	int				map_columns;
	int				player_x;
	int				player_y;
	char			player_orientation;
	int				ratio;
	uint32_t		ceiling_color;
	uint32_t		floor_color;
	mlx_texture_t	*t_tex00;
	mlx_texture_t	*t_tex01;
	mlx_texture_t	*t_tex02;
	mlx_texture_t	*t_tex03;
	mlx_texture_t	*t_tex04;
	mlx_texture_t	*t_tex05;
	mlx_texture_t	*t_tex06;
	mlx_texture_t	*t_tex07;
	mlx_texture_t	*torch_tex;
	mlx_image_t		*t_image00;
	mlx_image_t		*t_image01;
	mlx_image_t		*t_image02;
	mlx_image_t		*t_image03;
	mlx_image_t		*t_image04;
	mlx_image_t		*t_image05;
	mlx_image_t		*t_image06;
	mlx_image_t		*t_image07;
	mlx_image_t		*torch_img;
	int				torch_animation_speed;
	int				actual_torch_frame;
	int				torch_frame_counter;
	t_tex			*tex;
	t_img			*img;
	t_ray			*ray;
	t_player		*ply;
}	t_game;

/* animation.c */
void		load_torch_textures(t_game *g);
void		draw_torch(t_game *g);
/* extension.c */
void		parse_ext(char *av);
/* file.c */
void		get_file(t_game *g, char *file);
void		get_tex_color(t_game *g);
void		tokenizing(t_game *g, char **texture, char **tokens, int *flag);
/* flood_fill.c */
void		player_position(t_game *g);
void		map_orientation(t_game *g);
double		get_colum(t_game *g);
void		check_map(t_game *g);
/* free_error_exit.c */
void		free_error(char *msg, t_game *g);
void		win_game(char *msg, t_game *g);
int			sign(double n);
/* get_colors.c  */
int			get_colors(t_game *g, int i);
/* get_textures.c  */
int			get_textures(t_game *g, int i);
/* images1.c */
uint32_t	get_pixel_color(t_game *g, int size, int tex_colum);
/* images2.c */
void		init_textures(t_game *g);
int			check_comas(char *rgb);
uint32_t	interpretate_color(t_game *g, char *color);
/* init_data.c */
void		malloc_data(t_game *g);
void		init_data_1(t_game *g);
void		init_data_2(t_game *g);
void		check_inits(t_game *g);
/* map.c */
void		get_map(t_game *g, int index);
/* movements.c */
void		rotate_player(t_game *g);
void		ft_game_hook(void *param);
void		ft_key_release(mlx_key_data_t keydata, t_game *g);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
/* raycast.c */
void		raycast(void *param);
/* render.c */
int			get_size(t_ray *ray);
void		ft_clear_window(t_game *g);
void		render(t_game *g, int i);
void		get_h_surface(t_game *g);
void		get_v_surface(t_game *g);
/* run_game.c*/
void		ft_mouse_hook(void *param);
void		run_game(t_game *g);

#endif