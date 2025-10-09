/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_north.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 16:53:05 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-08 16:53:05 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

int	fill_sprite(char **element, t_game *game)
{
	int	fd;

	if (game->S != 0)
		return (-1);
	if (element[1])
	{
		if(element[1][ft_strlen(element[1]) - 1] == '\n')
			element[1][ft_strlen(element[1]) - 1] = 0;
		fd = open(element[1], O_RDONLY);
		if (fd < 0)
			return (-1);
		close(fd);
		game->S = ft_strdup(element[1]);
	}
	else
		return (-1);
	return (0);
}