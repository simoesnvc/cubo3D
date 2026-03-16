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
