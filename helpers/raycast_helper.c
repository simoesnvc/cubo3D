/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-18 18:14:27 by jdoutor-          #+#    #+#             */
/*   Updated: 2026-03-18 18:14:27 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubo3d.h"

void	perform_ray_marching(t_ray *ray, t_game *game)
{
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_x < 0 || !game->map[ray->map_y]
			|| !game->map[ray->map_y][ray->map_x])
			break ;
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_perpendicular_wall_dist(t_ray *ray,
			double ray_dir_x, double ray_dir_y)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->ray_pos_x
				+(1 - ray->step_x) / 2) / ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->ray_pos_y
				+ (1 - ray->step_y) / 2) / ray_dir_y;
	if (ray->perp_wall_dist <= 0.0001)
		ray->perp_wall_dist = 0.0001;
}

void	calculate_wall_and_texture(t_ray *ray,
			double ray_dir_x, double ray_dir_y)
{
	ray->wall_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->start_y = (HEIGHT / 2) - (ray->wall_height / 2);
	ray->end_y = (HEIGHT / 2) + (ray->wall_height / 2);
	if (ray->start_y < 0)
		ray->start_y = 0;
	if (ray->end_y >= HEIGHT)
		ray->end_y = HEIGHT - 1;
	if (ray->side == 0 && ray_dir_x > 0)
		ray->texnum = EAST;
	else if (ray->side == 0 && ray_dir_x < 0)
		ray->texnum = WEST;
	else if (ray->side == 1 && ray_dir_y > 0)
		ray->texnum = SOUTH;
	else
		ray->texnum = NORTH;
}

void	calculate_texture_coordinates(t_ray *ray, t_game *game,
			double ray_dir_x, double ray_dir_y)
{
	if (ray->side == 0)
		ray->wallx = ray->ray_pos_y + ray->perp_wall_dist * ray_dir_y;
	else
		ray->wallx = ray->ray_pos_x + ray->perp_wall_dist * ray_dir_x;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)game->textures[ray->texnum].width);
	if ((ray->side == 0 && ray_dir_x > 0) || (ray->side == 1 && ray_dir_y < 0))
		ray->texx = game->textures[ray->texnum].width - ray->texx - 1;
	ray->step = 1.0 * game->textures[ray->texnum].height / ray->wall_height;
	ray->texpos = (ray->start_y - HEIGHT / 2 + ray->wall_height / 2)
		* ray->step;
}

void	draw_pixels(t_ray *ray, t_game *game, int screen_x)
{
	ray->y = ray->start_y;
	while (ray->y <= ray->end_y)
	{
		ray->texy = (int)ray->texpos & (game->textures[ray->texnum].height - 1);
		ray->texpos += ray->step;
		ray->dst = game->textures[ray->texnum].addr
			+ (ray->texy * game->textures[ray->texnum].line_length
				+ ray->texx * (game->textures[ray->texnum].bpp / 8));
		ray->color = *(unsigned int *)ray->dst;
		my_mlx_pixel_put(&game->screen, screen_x, ray->y, ray->color);
		ray->y++;
	}
}
