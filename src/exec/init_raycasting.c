/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:11:15 by dev               #+#    #+#             */
/*   Updated: 2025/12/01 17:32:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

static void	init_dist_step(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->dist_step_x = 1e30;
	else
		ray->dist_step_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->dist_step_y = 1e30;
	else
		ray->dist_step_y = fabs(1.0 / ray->ray_dir_y);
}

static void	init_step_x(t_data *data, t_ray *ray)
{
	double	dx;

	if (ray->ray_dir_x < 0)
	{
		ray->step_dir_x = -1;
		ray->total_dist_x = (data->player.x - ray->grid_x) * ray->dist_step_x;
	}
	else
	{
		dx = ray->grid_x + 1.0 - data->player.x;
		ray->step_dir_x = 1;
		ray->total_dist_x = dx * ray->dist_step_x;
	}
}

static void	init_step_y(t_data *data, t_ray *ray)
{
	double	dy;

	if (ray->ray_dir_y < 0)
	{
		ray->step_dir_y = -1;
		ray->total_dist_y = (data->player.y - ray->grid_y) * ray->dist_step_y;
	}
	else
	{
		dy = ray->grid_y + 1.0 - data->player.y;
		ray->step_dir_y = 1;
		ray->total_dist_y = dy * ray->dist_step_y;
	}
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)data->screen_w - 1.0;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->grid_x = (int)data->player.x;
	ray->grid_y = (int)data->player.y;
	ray->wall_hit = 0;
	init_dist_step(ray);
	init_step_x(data, ray);
	init_step_y(data, ray);
}
