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

int	fill_floor(char **element, t_game *game)
{
	int		R;
	int		G;
	int		B;
	char	**split;

	if (game->F_R != -1 || game->F_G != -1 || game->F_B != -1)
		return (-1);
	if (element[1])
		split = ft_split(element[1], ',');
	if (split[0])
	{
		R = ft_atoi(split[0]);
		if (R >= 0 && R <= 255)
			game->F_R = R;
		else
		{
			ft_freestrs(split);
			return (-1);
		}
	}
	else
		{
			ft_freestrs(split);
			return (-1);
		}
	if (split[1])
	{
		G = ft_atoi(split[1]);
		if (G >= 0 && G <= 255)
			game->F_G = G;
		else
		{
			ft_freestrs(split);
			return (-1);
		}
	}
	else
		{
			ft_freestrs(split);
			return (-1);
		}
	if (split[2])
	{
		B = ft_atoi(split[2]);
		if (B >= 0 && B <= 255)
			game->F_B = B;
		else
		{
			ft_freestrs(split);
			return (-1);
		}
	}
	else
		{
			ft_freestrs(split);
			return (-1);
		}
	if (split[3] != 0 || element[2] !=0)
		{
			ft_freestrs(split);
			return (-1);
		}
	ft_freestrs(split);
	return (0);
}