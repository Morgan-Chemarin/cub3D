/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:32:01 by dev               #+#    #+#             */
/*   Updated: 2025/11/27 18:39:29 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	calc_perp(t_ray *ray)
{
	if (!ray->side)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

void	dda(t_data *data, t_ray *ray, int x)
{
	double	perp_wall_lengt;

	while (ray->hit == 0)
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
		if (ray->map_y < 0 || ray->map_y >= data->map.map_length
			|| ray->map_x < 0 || ray->map_x >= data->map.map_width)
			return ;
		if (data->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	perp_wall_lengt = calc_perp(ray);
	draw_wall(perp_wall_lengt, data, ray, x);
}
