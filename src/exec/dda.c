/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:32:01 by dev               #+#    #+#             */
/*   Updated: 2025/11/22 22:43:39 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

static void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x < 0 || x >= data->screen_w || y < 0 || y >= data->screen_h)
		return ;
	char *dst = data->img.addr + y * data->img.line_len + x * (data->img.bpp / 8);
	*(int *)dst = color;
}

static double	calc_perp(t_ray *ray)
{
	if (!ray->side)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

static void	draw_wall(double perp_wall, t_data *data, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;

	line_height = (int)(data->screen_h / perp_wall);
	draw_start = -line_height / 2 + data->screen_h / 2;
	draw_end = line_height / 2 + data->screen_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= data->screen_h)
		draw_end = data->screen_h - 1;
	if (ray->side == 1)
		color = 0x00777777;
	else
		color = 0xffff00;
	y = draw_start;
	while (y <= draw_end)
	{
		put_pixel(data, x, y, color);
		y++;
	}
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
