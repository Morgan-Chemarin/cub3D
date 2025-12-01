/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:32:01 by dev               #+#    #+#             */
/*   Updated: 2025/12/01 17:26:10 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	compute_wall_dist(t_ray *ray)
{
	if (!ray->axis_orientation)
		return (ray->dist_to_side_x - ray->dist_step_x);
	else
		return (ray->dist_to_side_y - ray->dist_step_y);
}

static void	advance_ray(t_ray *ray)
{
	bool	is_x_closer;

	is_x_closer = (ray->dist_to_side_x < ray->dist_to_side_y);
	ray->axis_orientation = !is_x_closer;
	if (is_x_closer)
	{
		ray->dist_to_side_x += ray->dist_step_x;
		ray->grid_x += ray->step_dir_x;
	}
	else
	{
		ray->dist_to_side_y += ray->dist_step_y;
		ray->grid_y += ray->step_dir_y;
	}
}

void	raycasting(t_data *data, t_ray *ray, int x)
{
	double	corrected_dist;

	while (true)
	{
		advance_ray(ray);
		if (ray->grid_y < 0 || ray->grid_y >= data->map.map_length
			|| ray->grid_x < 0 || ray->grid_x >= data->map.map_width)
			break ;
		if (data->map.map[ray->grid_y][ray->grid_x] == '1')
		{
			ray->wall_hit = 1;
			break ;
		}
	}
	if (ray->wall_hit)
	{
		corrected_dist = compute_wall_dist(ray);
		draw_wall(corrected_dist, data, ray, x);
	}
}
