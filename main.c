/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 12:48:00 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-06 12:48:00 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubo3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	validate_args(argc, argv);
	game = malloc(sizeof(t_game));
	init_struct(game);
	validate_file(argv[1], game);
	free (game->mlx);
	free(game->NO);
	free(game->SO);
	free(game->WE);
	free(game->EA);
	free(game->S);
	ft_freestrs(game->map);
	free (game);
}