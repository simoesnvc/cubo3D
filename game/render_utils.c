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
	while (!ray.hit)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (ray.map_y < 0 || ray.map_x < 0 || !game->map[ray.map_y]
			|| !game->map[ray.map_y][ray.map_x])
			break ;
		if (game->map[ray.map_y][ray.map_x] == '1')
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.perp_wall_dist = (ray.map_x - ray.ray_pos_x + (1 - ray.step_x) / 2)
			/ ray_dir_x;
	else
		ray.perp_wall_dist = (ray.map_y - ray.ray_pos_y + (1 - ray.step_y) / 2)
			/ ray_dir_y;
	if (ray.perp_wall_dist <= 0.0001)
		ray.perp_wall_dist = 0.0001;
	ray.wall_height = (int)(HEIGHT / ray.perp_wall_dist);
	ray.start_y = (HEIGHT / 2) - (ray.wall_height / 2);
	ray.end_y = (HEIGHT / 2) + (ray.wall_height / 2);
	if (ray.start_y < 0)
		ray.start_y = 0;
	if (ray.end_y >= HEIGHT)
		ray.end_y = HEIGHT - 1;
	if (ray.side == 0 && ray_dir_x > 0)
		ray.texnum = EAST;
	else if (ray.side == 0 && ray_dir_x < 0)
		ray.texnum = WEST;
	else if (ray.side == 1 && ray_dir_y > 0)
		ray.texnum = SOUTH;
	else
		ray.texnum = NORTH;
	if (ray.side == 0)
		ray.wallx = ray.ray_pos_y + ray.perp_wall_dist * ray_dir_y;
	else
		ray.wallx = ray.ray_pos_x + ray.perp_wall_dist * ray_dir_x;
	ray.wallx -= floor(ray.wallx);
	ray.texx = (int)(ray.wallx * (double)game->textures[ray.texnum].width);
	if ((ray.side == 0 && ray_dir_x > 0) || (ray.side == 1 && ray_dir_y < 0))
		ray.texx = game->textures[ray.texnum].width - ray.texx - 1;
	ray.step = 1.0 * game->textures[ray.texnum].height / ray.wall_height;
	ray.texpos = (ray.start_y - HEIGHT / 2 + ray.wall_height / 2) * ray.step;
	ray.y = ray.start_y;
	while (ray.y <= ray.end_y)
	{
		ray.texy = (int)ray.texpos & (game->textures[ray.texnum].height - 1);
		ray.texpos += ray.step;
		ray.dst = game->textures[ray.texnum].addr
			+ (ray.texy * game->textures[ray.texnum].line_length
				+ ray.texx * (game->textures[ray.texnum].bpp / 8));
		ray.color = *(unsigned int *)ray.dst;
		my_mlx_pixel_put(&game->screen, screen_x, ray.y, ray.color);
		ray.y++;
	}
}
