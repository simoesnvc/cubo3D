/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 12:48:20 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 12:48:20 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBO3D_H
# define CUBO3D_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

enum e_texture_dir
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct game
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	**map;
	double	start_x;
	double	start_y;
	char	start_orientation;
	void	*mlx;
	void	*win;
	t_img	screen;
	t_img	textures[4];
	double	posx;
	double	posy;
	double	dir_x;
	double	dir_y;
	double	planex;
	double	planey;
	double	move_speed;
	double	rot_speed;
}	t_game;

# define WIDTH 800
# define HEIGHT 600
# define M_PI 3.14159265358979323846
# define FOV 1.0471975512
# define ESC	65307
# define W	119
# define S	115
# define A	97
# define D	100
# define LEFT	65361
# define RIGHT	65363

int		main(int argc, char **argv);
void	validate_args(int argc, char **argv);
void	init_struct(t_game	*game);
void	validate_file(char *file, t_game *game);
int		fill_north(char **element, t_game *game);
int		fill_south(char **element, t_game *game);
int		fill_west(char **element, t_game *game);
int		fill_east(char **element, t_game *game);
int		fill_floor(char **element, t_game *game);
int		fill_ceilling(char **element, t_game *game);
int		fill_map(char *line, int fd, t_game *game);
int		validate_map(t_game *game);
void	load_textures(t_game *game);
void	free_all(t_game *game);
void	start_game(t_game *game);
int		render(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
double	calculate_ray_angle(t_game *game, int x);
void	cast_single_ray(t_game *game, int screen_x,
			double ray_dir_x, double ray_dir_y);
int		exit_game(t_game *game);
int		key_input(int keycode, t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_forward(t_game *game);
void	move_backwards(t_game *game);
void	rotate(int keycode, t_game *game);
void	north(t_game *game);
void	south(t_game *game);
void	east(t_game *game);
void	west(t_game *game);
int		fill_var_cont(char **element, t_game *game);
void	ready_to_fill(int fd, char *line, t_game *game);
#endif