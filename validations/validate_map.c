/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:09:23 by jdoutor-          #+#    #+#             */
/*   Updated: 2026/03/18 01:30:27 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static int	check_walls(t_game *game)
{
	int	i;

	i = check_top_left_walls(game);
	if (i == -1)
		return (-1);
	if (check_bottom_right_walls(game, i) == -1)
		return (-1);
	return (0);
}

static int	valid_adjacent_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

static int	valid_space(t_game *game, int i, int j)
{
	if (i <= 0 || !game->map[i - 1] || j >= (int)ft_strlen(game->map[i - 1])
		|| !valid_adjacent_char(game->map[i - 1][j]))
		return (-1);
	if (!game->map[i + 1] || j >= (int)ft_strlen(game->map[i + 1])
		|| !valid_adjacent_char(game->map[i + 1][j]))
		return (-1);
	if (j <= 0 || !valid_adjacent_char(game->map[i][j - 1]))
		return (-1);
	if (j + 1 >= (int)ft_strlen(game->map[i])
		|| !valid_adjacent_char(game->map[i][j + 1]))
		return (-1);
	return (0);
}

static int	save_p(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		return (0);
	if (game->start_orientation != 0)
		return (-1);
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S')
	{
		if (game->map[i][j] == 'N')
			game->start_orientation = 'N';
		else
			game->start_orientation = 'S';
		game->start_x = j;
		game->start_y = i;
	}
	else if (game->map[i][j] == 'E' || game->map[i][j] == 'W')
	{
		if (game->map[i][j] == 'E')
			game->start_orientation = 'E';
		else
			game->start_orientation = 'W';
		game->start_x = j;
		game->start_y = i;
	}
	return (0);
}

int	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	if (check_walls(game) == -1)
		return (-1);
	while (game->map[i] != 0)
	{
		j = 1;
		while (game->map[i][j] != 0 && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W')
			{
				if (valid_space(game, i, j) == -1 || save_p(game, i, j) == -1)
					return (-1);
			}
			else if (game->map[i][j] != '1' && game->map[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (no_start(game));
}
