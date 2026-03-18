/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 00:52:21 by aralves-          #+#    #+#             */
/*   Updated: 2026/03/18 01:18:56 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

void	load_one_texture(t_game *game, int dir, char *path)
{
	game->textures[dir].img = mlx_xpm_file_to_image(game->mlx, path,
			&game->textures[dir].width, &game->textures[dir].height);
	if (!game->textures[dir].img)
	{
		printf("Error loading texture: %s\n", path);
		free_all(game);
		exit(7);
	}
}
