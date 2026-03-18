/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-16 15:42:17 by jdoutor-          #+#    #+#             */
/*   Updated: 2026-03-16 15:42:17 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

int	fill_var_cont(char **element, t_game *game)
{
	if (ft_strcmp(element[0], "EA") == 0)
	{
		if (fill_east(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "F") == 0)
	{
		if (fill_floor(element, game) == -1)
			return (-1);
	}
	else if (ft_strcmp(element[0], "C") == 0)
	{
		if (fill_ceilling(element, game) == -1)
			return (-1);
	}
	return (0);
}

void	ready_to_fill(int fd, char *line, t_game *game)
{
	int		is_filled;

	is_filled = fill_map(line, fd, game);
	if (is_filled != 1)
	{
		printf("Error in validation\n");
		close(fd);
		free_all(game);
		exit(5);
	}
	close(fd);
}

int	check_top_left_walls(t_game *game)
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
	return (i);
}

int	check_bottom_right_walls(t_game *game, int i)
{
	int	y;

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

void	not_filled_close(int fd, t_game *game)
{
	printf("error with file content\n");
	close(fd);
	free_all(game);
	exit(22);
}
