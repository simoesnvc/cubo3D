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
	if (keycode == ESC)
	{
		free_all(game);
		exit (8);
	}
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	else if (keycode == S)
		move_backwards(game);
	else if (keycode == W)
		move_forward(game);
	else
		rotate(keycode, game);
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
	game->posx = game->start_x + 0.5;
	game->posy = game->start_y + 0.5;
	if (game->start_orientation == 'N')
		north(game);
	else if (game->start_orientation == 'S')
		south(game);
	else if (game->start_orientation == 'E')
		east(game);
	else if (game->start_orientation == 'W')
		west(game);
}

void	start_game(t_game *game)
{
	set_up_start(game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
