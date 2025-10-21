/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 14:26:58 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 14:26:58 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubo3d.h"

void	free_all(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
	}
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->NO);
	free(game->SO);
	free(game->WE);
	free(game->EA);
	ft_freestrs(game->map);
	free(game);
}

static void	fill_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
		&game->textures[i].bpp,
		&game->textures[i].line_length,
		&game->textures[i].endian);
	}
}

void	load_textures(t_game *game)
{
	game->textures[NORTH].img = mlx_xpm_file_to_image(game->mlx, game->NO,
		&game->textures[NORTH].width, &game->textures[NORTH].height);
	game->textures[SOUTH].img = mlx_xpm_file_to_image(game->mlx, game->SO,
		&game->textures[SOUTH].width, &game->textures[SOUTH].height);
	game->textures[WEST].img = mlx_xpm_file_to_image(game->mlx, game->WE,
		&game->textures[WEST].width, &game->textures[WEST].height);
	game->textures[EAST].img = mlx_xpm_file_to_image(game->mlx, game->EA,
		&game->textures[EAST].width, &game->textures[EAST].height);
	if (!game->textures[NORTH].img || !game->textures[SOUTH].img
	|| !game->textures[WEST].img || !game->textures[EAST].img)
	{
		printf("Failed to load texture\n");
		free_all(game);
		exit(7);
	}
	fill_textures(game);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Failed to initialize MLX\n");
		exit(4);
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		printf("Failed to create window\n");
		exit(6);
	}
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L<<0, key_input, game);
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp, &game->screen.line_length, &game->screen.endian);
}

void	init_struct(t_game	*game)
{
	game->NO = 0;
	game->SO = 0;
	game->WE = 0;
	game->EA = 0;
	game->F_R = -1;
	game->F_G = -1;
	game->F_B = -1;
	game->C_R = -1;
	game->C_G = -1;
	game->C_B = -1;
	game->map = 0;
	game->start_x = -1;
	game->start_y = -1;
	game->start_orientation = 0;
	init_mlx(game);
	game->posX = -1;
	game->posY = -1;
	game->move_speed = 0.05;
	game->rot_speed = 0.04;
	game->dir_x = -1;
	game->dir_y = -1;
	game->planeX = -1;
	game->planeY = -1;
}