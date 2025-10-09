/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 13:02:18 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 13:02:18 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static int	valid_map_name(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i > 4 && argv[i - 1] == 'b' && argv[i - 2] == 'u'
		&& argv[i - 3] == 'c' && argv[i - 4] == '.')
		return (1);
	return (0);
}

void	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Invalid arguments.\n");
		exit(1);
	}
	if (!valid_map_name(argv[1]))
	{
		printf("Invalid map name.\n");
		exit(2);
	}
}
