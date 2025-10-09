/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 16:25:54 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 16:25:54 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

int	fill_resolution(char **element, t_game *game)
{
	int	x;
	int	x_max;
	int	y;
	int	y_max;

	if (game->R_x != -1 || game->R_y != -1)
		return (-1);
	mlx_get_screen_size(game->mlx, &x_max, &y_max);
	if (element[1])
	{
		x = ft_atoi(element[1]);
		if (x > 0 && x <= x_max)
			game->R_x = x;
		else
			return (-1);
	}
	else
		return (-1);
	if (element[2])
	{
		y = ft_atoi(element[2]);
		if (y > 0 && y <= y_max)
			game->R_y = y;
		else
			return (-1);
	}
	else
		return (-1);
	if (element[3] != 0)
		return (-1);
	return (0);
}