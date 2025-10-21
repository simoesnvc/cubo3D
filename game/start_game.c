/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-14 12:45:45 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-14 12:45:45 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

int	key_input(int keycode, t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == ESC)
	{
		free_all(game);
		exit (8);
	}
	else if (keycode == A)
	{
		if (game->map[(int)(game->posY)][(int)(game->posX - game->planeX * game->move_speed)] != '1')
			game->posX -= game->planeX * game->move_speed;
		if (game->map[(int)(game->posY - game->planeY * game->move_speed)][(int)(game->posX)] != '1')
			game->posY -= game->planeY * game->move_speed;
	}
	else if (keycode == D)
	{
		if (game->map[(int)(game->posY)][(int)(game->posX + game->planeX * game->move_speed)] != '1')
			game->posX += game->planeX * game->move_speed;
		if (game->map[(int)(game->posY + game->planeY * game->move_speed)][(int)(game->posX)] != '1')
			game->posY += game->planeY * game->move_speed;
	}
	else if (keycode == S)
	{
		if (game->map[(int)(game->posY)][(int)(game->posX - game->dir_x * game->move_speed)] != '1')
			game->posX -= game->dir_x * game->move_speed;
		if (game->map[(int)(game->posY - game->dir_y * game->move_speed)][(int)(game->posX)] != '1')
			game->posY -= game->dir_y * game->move_speed;
	}
	else if (keycode == W)
	{
		if (game->map[(int)(game->posY)][(int)(game->posX + game->dir_x * game->move_speed)] != '1')
			game->posX += game->dir_x * game->move_speed;
		if (game->map[(int)(game->posY + game->dir_y * game->move_speed)][(int)(game->posX)] != '1')
			game->posY += game->dir_y * game->move_speed;
	}
	else if (keycode == LEFT)
	{
		oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(-game->rot_speed) - game->dir_y * sin(-game->rot_speed);
		game->dir_y = oldDirX * sin(-game->rot_speed) + game->dir_y * cos(-game->rot_speed);
		oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(-game->rot_speed) - game->planeY * sin(-game->rot_speed);
		game->planeY = oldPlaneX * sin(-game->rot_speed) + game->planeY * cos(-game->rot_speed);
	}
	else if (keycode == RIGHT)
	{
		oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(game->rot_speed) - game->dir_y * sin(game->rot_speed);
		game->dir_y = oldDirX * sin(game->rot_speed) + game->dir_y * cos(game->rot_speed);
		oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(game->rot_speed) - game->planeY * sin(game->rot_speed);
		game->planeY = oldPlaneX * sin(game->rot_speed) + game->planeY * cos(game->rot_speed);
	}
	return (0);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit (8);
	return (0);
}

static void	set_up_start(t_game *game)
{
	game->posX = game->start_x + 0.5;
	game->posY = game->start_y + 0.5;
	if (game->start_orientation == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->planeX = FOV;
		game->planeY = 0;
	}
	else if (game->start_orientation == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->planeX = -FOV;
		game->planeY = 0;
	}
	else if (game->start_orientation == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->planeX = 0;
		game->planeY = FOV;
	}
	else if (game->start_orientation == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->planeX = 0;
		game->planeY = -FOV;
	}
}

void	start_game(t_game *game)
{
	set_up_start(game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}