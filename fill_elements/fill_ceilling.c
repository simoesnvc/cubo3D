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

static int	parse_color_value(char **split, int index, int *color_value)
{
	int	color;

	if (split[index])
	{
		color = ft_atoi(split[index]);
		if (color >= 0 && color <= 255)
		{
			*color_value = color;
			return (0);
		}
	}
	return (-1);
}

int	fill_ceilling(char **element, t_game *game)
{
	char	**split;

	if (game->c_r != -1 || game->c_g != -1 || game->c_b != -1)
		return (-1);
	if (element[1])
		split = ft_split(element[1], ',');
	if (parse_color_value(split, 0, &game->c_r) == -1
		|| parse_color_value(split, 1, &game->c_g) == -1
		|| parse_color_value(split, 2, &game->c_b) == -1)
	{
		ft_freestrs(split);
		return (-1);
	}
	if (split[3] != 0 || element[2] != 0)
	{
		ft_freestrs(split);
		return (-1);
	}
	ft_freestrs(split);
	return (0);
}
