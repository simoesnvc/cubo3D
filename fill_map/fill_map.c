/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 12:23:20 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-09 12:23:20 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static int	check_walls(t_game *game)
{
	int	i;
	int	y;

	i = -1;
	y = -1;
	while (game->map[++i])
		y++;
	i = 0;
	
	while (game->map[0][i] != 0 && game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' ')
			return (-1);
		i++;
	}
	i = 0;
	while (game->map[y][i] != 0 && game->map[y][i] != '\n')
	{
		if (game->map[y][i] != '1' && game->map[y][i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

static int	validate_map(t_game *game)
{
	int	i;
	int	j;
	int	max_y;
	int	tile_x;
	size_t	current_size;
	size_t	last_size;

	i = -1;
	max_y = 0;
	while (game->map[++i])
		max_y++;
	max_y--;
	i = 0;
	last_size = ft_strlen(game->map[0]);
	if (check_walls(game) == -1)
		return (-1);
	while (game->map[i])
	{
		j = 0;
		current_size = ft_strlen(game->map[i]);
		if (current_size != last_size)
		{
			if(i == max_y && ((current_size + 1) == last_size))
				break;
			return (-1);
		}
		if (game->map[i][0] != '1' || game->map[i][current_size - 2] != '1')
		{
			return (-1);
		}
		tile_x = 0;
		while (game->map[i][j] != 0 && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == ' ')
			{
				j++;
				continue;
			}
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != '2' && game->map[i][j] != 'N'
				&& game->map[i][j] != 'S' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'W' && game->map[i][j] != ' ')
				return (-1);
			else if (game->map[i][j] == 'N'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W')
			{
				if (game->start_orientation != 0)
					return (-1);
				game->start_orientation = game->map[i][j];
				game->start_x = tile_x;
				game->start_y = i;
			}
			else if (game->map[i][j] == '2')
				game->n_items++;
			tile_x++;
			j++;
		}
		i++;
	}
	if (game->start_orientation == 0 || game->start_x == -1 || game->start_y == -1)
		return (-1);
	return (1);
}

int	fill_map(char *line, int fd, t_game *game)
{
	int		i;
	int		count;
	char	**temp_map;

	count = 0;
	while (line != 0)
	{
		i = 0;
		temp_map = malloc(sizeof(char *) * (count + 2));
		if (!temp_map)
			return (-1);
		while (i < count)
		{
			temp_map[i] = game->map[i];
			i++;
		}
		temp_map[count] = ft_strdup(line);
		temp_map[count + 1] = 0;
		free(game->map);
		game->map = temp_map;
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (validate_map(game));
}