/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:51:58 by jdoutor-          #+#    #+#             */
/*   Updated: 2026/03/18 02:16:16 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

static void	helper_init(t_ray *ray, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->ray_pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->ray_pos_x)
			* ray->delta_dist_x;
	}
}

static	void	init_ray_vars(t_ray *ray, t_game *game,
	double ray_dir_x, double ray_dir_y)
{
	ray->ray_pos_x = game->posx;
	ray->ray_pos_y = game->posy;
	ray->map_x = (int)ray->ray_pos_x;
	ray->map_y = (int)ray->ray_pos_y;
	ray->hit = 0;
	helper_init(ray, ray_dir_x, ray_dir_y);
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->ray_pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->ray_pos_y)
			* ray->delta_dist_y;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	calculate_ray_angle(t_game *game, int x)
{
	double	camera_x;
	double	ray_angle;
	double	dir_angle;

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
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	return (ray_angle);
}

void	cast_single_ray(t_game *game, int screen_x,
			double ray_dir_x, double ray_dir_y)
{
	t_ray	ray;

	init_ray_vars(&ray, game, ray_dir_x, ray_dir_y);
	perform_ray_marching(&ray, game);
	calculate_perpendicular_wall_dist(&ray, ray_dir_x, ray_dir_y);
	calculate_wall_and_texture(&ray, ray_dir_x, ray_dir_y);
	calculate_texture_coordinates(&ray, game, ray_dir_x, ray_dir_y);
	draw_pixels(&ray, game, screen_x);
}
