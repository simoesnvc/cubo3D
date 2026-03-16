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
		exit(5);
	}
	close(fd);
}
