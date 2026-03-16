/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 15:09:23 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-13 15:09:23 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static int	check_walls(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game->map[0][y] != '\n' && game->map[0][y] != 0)
	{
		if ((game->map[0][y] != '1') && (game->map[0][y] != ' '))
			return (-1);
		y++;
	}
	while (game->map[i] != 0 && game->map[i][0] != '\n' && game->map[i][0] != 0)
	{
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
			return (-1);
		i++;
	}
	y = 0;
	i--;
	while (game->map[i][y] != '\n' && game->map[i][y] != 0)
	{
		if (game->map[i][y] != '1' && game->map[i][y] != ' ')
			return (-1);
		y++;
	}
	i--;
	while (i >= 0)
	{
		if (game->map[i][ft_strlen(game->map[i]) - 2] != '1' &&
				game->map[i][ft_strlen(game->map[i]) - 2] != ' ')
			return (-1);
		i--;
	}
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

static int	save_position(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		return (0);
	if (game->start_orientation != 0)
		return (-1);
	if (game->map[i][j] == 'N')
	{
		game->start_orientation = 'N';
		game->start_x = j;
		game->start_y = i;
	}
	else if (game->map[i][j] == 'S')
	{
		game->start_orientation = 'S';
		game->start_x = j;
		game->start_y = i;
	}
	else if (game->map[i][j] == 'E')
	{
		game->start_orientation = 'E';
		game->start_x = j;
		game->start_y = i;
	}
	else if (game->map[i][j] == 'W')
	{
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
	j = 1;
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
				if (valid_space(game, i, j) == -1
					|| save_position(game, i, j) == -1)
					return (-1);
			}
			else if (game->map[i][j] != '1' && game->map[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
