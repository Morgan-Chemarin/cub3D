/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:11:15 by dev               #+#    #+#             */
/*   Updated: 2025/11/18 17:50:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

static void	init_delta_dist(t_ray *ray)
{
    if (ray->ray_dir_x == 0)
        ray->delta_dist_x = 1e30;
    else
        ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
    if (ray->ray_dir_y == 0)
        ray->delta_dist_y = 1e30;
    else
        ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

static void	init_step_x(t_data *data, t_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
    }
}

static void	init_step_y(t_data *data, t_ray *ray)
{
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
    }
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
    ray->camera_x = 2.0 * x / (double)data->screen_w - 1.0;
    ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
    ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
    ray->map_x = (int)data->player.x;
    ray->map_y = (int)data->player.y;
    ray->hit = 0;
    init_delta_dist(ray);
    init_step_x(data, ray);
    init_step_y(data, ray);
}
