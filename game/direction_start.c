/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-16 15:35:23 by jdoutor-          #+#    #+#             */
/*   Updated: 2026-03-16 15:35:23 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

void	north(t_game *game)
{
	game->dir_x = 0;
	game->dir_y = -1;
	game->planex = FOV;
	game->planey = 0;
}

void	south(t_game *game)
{
	game->dir_x = 0;
	game->dir_y = 1;
	game->planex = -FOV;
	game->planey = 0;
}

void	east(t_game *game)
{
	game->dir_x = 1;
	game->dir_y = 0;
	game->planex = 0;
	game->planey = FOV;
}

void	west(t_game *game)
{
	game->dir_x = -1;
	game->dir_y = 0;
	game->planex = 0;
	game->planey = -FOV;
}
