/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:26:58 by jdoutor-          #+#    #+#             */
/*   Updated: 2026/03/18 01:20:20 by aralves-         ###   ########.fr       */
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
	free(game->no);
	free(game->so);
	free(game->we);
	free(game->ea);
	ft_freestrs(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

static void	fill_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->textures[i].img == NULL)
		{
			printf("Texture %d not loaded properly!\n", i);
			exit(7);
		}
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bpp,
				&game->textures[i].line_length,
				&game->textures[i].endian);
	}
}

void	load_textures(t_game *game)
{
	char	*paths[4];
	int		i;

	if (!game->no || !game->so || !game->we || !game->ea)
		return (printf("Error: missing texture path\n"), exit(7));
	paths[NORTH] = game->no;
	paths[SOUTH] = game->so;
	paths[WEST] = game->we;
	paths[EAST] = game->ea;
	i = -1;
	while (++i < 4)
		load_one_texture(game, i, paths[i]);
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
	mlx_hook(game->win, 2, 1L << 0, key_input, game);
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bpp, &game->screen.line_length, &game->screen.endian);
}

void	init_struct(t_game	*game)
{
	game->no = 0;
	game->so = 0;
	game->we = 0;
	game->ea = 0;
	game->f_r = -1;
	game->f_g = -1;
	game->f_b = -1;
	game->c_r = -1;
	game->c_g = -1;
	game->c_b = -1;
	game->map = 0;
	game->start_x = -1;
	game->start_y = -1;
	game->start_orientation = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->posx = -1;
	game->posy = -1;
	game->move_speed = 0.05;
	game->rot_speed = 0.04;
	game->dir_x = -1;
	game->dir_y = -1;
	game->planex = -1;
	game->planey = -1;
	init_mlx(game);
}
