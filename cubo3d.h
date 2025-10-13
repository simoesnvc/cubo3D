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
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct game
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int		F_R;
	int		F_G;
	int		F_B;
	int		C_R;
	int		C_G;
	int		C_B;
	char	**map;
	void	*mlx;
	double	start_x;
	double	start_y;
	char	start_orientation;
}	t_game;

int		main(int argc, char **argv);
void	validate_args(int argc, char **argv);
void	init_struct(t_game	*game);
void	validate_file(char *file, t_game *game);
int		fill_north(char **element, t_game *game);
int		fill_south(char **element, t_game *game);
int		fill_west(char **element, t_game *game);
int		fill_east(char **element, t_game *game);
int		fill_sprite(char **element, t_game *game);
int		fill_floor(char **element, t_game *game);
int		fill_ceilling(char **element, t_game *game);
int		fill_map(char *line, int fd, t_game *game);
int		validate_map(t_game *game);
#endif