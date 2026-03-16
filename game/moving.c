/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-16 15:18:35 by jdoutor-          #+#    #+#             */
/*   Updated: 2026-03-16 15:18:35 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

void	move_left(t_game *game)
{
	if (game->map[(int)(game->posy)]
		[(int)(game->posx - game->planex * game->move_speed)] != '1')
		game->posx -= game->planex * game->move_speed;
	if (game->map[(int)(game->posy - game->planey * game->move_speed)]
		[(int)(game->posx)] != '1')
		game->posy -= game->planey * game->move_speed;
}

void	move_right(t_game *game)
{
	if (game->map[(int)(game->posy)]
		[(int)(game->posx + game->planex * game->move_speed)] != '1')
		game->posx += game->planex * game->move_speed;
	if (game->map[(int)(game->posy + game->planey * game->move_speed)]
		[(int)(game->posx)] != '1')
		game->posy += game->planey * game->move_speed;
}

void	move_forward(t_game *game)
{
	if (game->map[(int)(game->posy)]
		[(int)(game->posx + game->dir_x * game->move_speed)] != '1')
		game->posx += game->dir_x * game->move_speed;
	if (game->map[(int)(game->posy + game->dir_y * game->move_speed)]
		[(int)(game->posx)] != '1')
		game->posy += game->dir_y * game->move_speed;
}

void	move_backwards(t_game *game)
{
	if (game->map[(int)(game->posy)]
		[(int)(game->posx - game->dir_x * game->move_speed)] != '1')
		game->posx -= game->dir_x * game->move_speed;
	if (game->map[(int)(game->posy - game->dir_y * game->move_speed)]
		[(int)(game->posx)] != '1')
		game->posy -= game->dir_y * game->move_speed;
}
