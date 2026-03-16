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
	if (!game)
		return (0);
	init_struct(game);
	validate_file(argv[1], game);
	load_textures(game);
	start_game(game);
	free_all(game);
}
