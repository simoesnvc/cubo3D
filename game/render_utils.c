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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	calculate_ray_angle(t_game *game, int x)
{
	double	camera_x;
	double	ray_angle;
	double dir_angle;// Adjust based on player orientation

	// camera_x ranges from -1 (left) to +1 (right)
	camera_x = (2.0 * x / WIDTH) - 1.0;
	if (game->start_orientation == 'N')
		dir_angle = M_PI / 2;
	else if (game->start_orientation == 'S')
		dir_angle = 3 * M_PI / 2;
	else if (game->start_orientation == 'E')
		dir_angle = 0;
	else
		dir_angle = M_PI;
	ray_angle = dir_angle + camera_x * (FOV / 2);
	// Keep angle between 0 and 2π
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	return (ray_angle);
}

void	cast_single_ray(t_game *game, int screen_x, double ray_dir_x, double ray_dir_y)
{
	double ray_pos_x;
	double ray_pos_y;
	int map_x;
	int map_y;
	double delta_dist_x;
	double delta_dist_y;
	double side_dist_x;
	double side_dist_y;
	int step_x;
	int step_y;
	int hit;
	int side;
	double perp_wall_dist;
	int wall_height;
	int start_y;
	int end_y;
	int	y;

	ray_pos_x = game->posX;
	ray_pos_y = game->posY;
	map_x = (int)ray_pos_x;
	map_y = (int)ray_pos_y;
	hit = 0;
	if (ray_dir_x == 0)
		delta_dist_x = 1e30;
	else
		delta_dist_x = fabs(1.0 / ray_dir_x);
	if (ray_dir_y == 0)
		delta_dist_y = 1e30;
	else
		delta_dist_y = fabs(1.0 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (ray_pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - ray_pos_x) * delta_dist_x;
	}

	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - ray_pos_y) * delta_dist_y;
	}
	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}

		if (map_y < 0 || map_x < 0 || !game->map[map_y] || !game->map[map_y][map_x])
			break;

		if (game->map[map_y][map_x] == '1')
			hit = 1;
	}
	if (side == 0)
		perp_wall_dist = (map_x - ray_pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - ray_pos_y + (1 - step_y) / 2) / ray_dir_y;

	if (perp_wall_dist <= 0.0001)
		perp_wall_dist = 0.0001;
	wall_height = (int)(HEIGHT / perp_wall_dist);
	start_y = (HEIGHT / 2) - (wall_height / 2);
	end_y = (HEIGHT / 2) + (wall_height / 2);

	if (start_y < 0) start_y = 0;
	if (end_y >= HEIGHT) end_y = HEIGHT - 1;
	y = start_y;
	while (y<=end_y)
	{
		my_mlx_pixel_put(&game->screen, screen_x, y, 0xFF0000);
		y++;
	}
	for (int y = start_y; y <= end_y; y++)
		my_mlx_pixel_put(&game->screen, screen_x, y, 0xFF0000); // red wall
}
