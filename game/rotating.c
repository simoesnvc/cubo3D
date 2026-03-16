/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-16 15:28:18 by jdoutor-          #+#    #+#             */
/*   Updated: 2026-03-16 15:28:18 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static void	rotate_left(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->dir_x;
	game->dir_x = game->dir_x * cos(-game->rot_speed)
		- game->dir_y * sin(-game->rot_speed);
	game->dir_y = olddirx * sin(-game->rot_speed)
		+ game->dir_y * cos(-game->rot_speed);
	oldplanex = game->planex;
	game->planex = game->planex * cos(-game->rot_speed)
		- game->planey * sin(-game->rot_speed);
	game->planey = oldplanex * sin(-game->rot_speed)
		+ game->planey * cos(-game->rot_speed);
}

static void	rotate_right(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->dir_x;
	game->dir_x = game->dir_x * cos(game->rot_speed)
		- game->dir_y * sin(game->rot_speed);
	game->dir_y = olddirx * sin(game->rot_speed)
		+ game->dir_y * cos(game->rot_speed);
	oldplanex = game->planex;
	game->planex = game->planex * cos(game->rot_speed)
		- game->planey * sin(game->rot_speed);
	game->planey = oldplanex * sin(game->rot_speed)
		+ game->planey * cos(game->rot_speed);
}

void	rotate(int keycode, t_game *game)
{
	if (keycode == LEFT)
		rotate_left(game);
	else if (keycode == RIGHT)
		rotate_right(game);
}
