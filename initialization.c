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

void	init_struct(t_game	*game)
{
	game->NO = 0;
	game->SO = 0;
	game->WE = 0;
	game->EA = 0;
	game->S = 0;
	game->F_R = -1;
	game->F_G = -1;
	game->F_B = -1;
	game->C_R = -1;
	game->C_G = -1;
	game->C_B = -1;
	game->map = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Failed to initialize MLX\n");
		exit(4);
	}
	game->start_x = -1;
	game->start_y = -1;
	game->start_orientation = 0;
}