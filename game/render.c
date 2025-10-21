/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-14 12:51:58 by jdoutor-          #+#    #+#             */
/*   Updated: 2025-10-14 12:51:58 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static void	clear_image(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int		ceiling_color;
	int		floor_color;

	ceiling_color = (game->C_R << 16) | (game->C_G << 8) | game->C_B;
	floor_color = (game->F_R << 16) | (game->F_G << 8) | game->F_B;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(img, x, y, ceiling_color);
			else
				my_mlx_pixel_put(img, x, y, floor_color);
		}
	}
}

static void	cast_all_rays(t_game *game)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = (2.0 * x / WIDTH) - 1.0;
		ray_dir_x = game->dir_x + game->planeX * camera_x;
		ray_dir_y = game->dir_y + game->planeY * camera_x;
		cast_single_ray(game, x, ray_dir_x, ray_dir_y);
		x++;
	}
}

int	render(t_game *game)
{
	clear_image(game, &game->screen);
	cast_all_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}