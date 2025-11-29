/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:13:32 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/29 17:51:45 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

t_img	*get_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&data->textures[2]);
		else
			return (&data->textures[3]);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&data->textures[0]);
		else
			return (&data->textures[1]);
	}
}

int	get_texture_color(t_img *t, int x, int y)
{
	char	*destination;

	if (x < 0 || x >= t->width || y < 0 || y >= t->height)
		return (0);
	destination = t->addr + (y * t->line_len + x * (t->bpp / 8));
	return (*(unsigned int *)destination);
}

int	get_texture_x(t_data *data, t_ray *ray, double perp_wall, t_img *texture)
{
	int		texture_x;
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.y + perp_wall * ray->ray_dir_y;
	else
		wall_x = data->player.x + perp_wall * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		texture_x = texture->width - texture_x - 1;
	return (texture_x);
}

void	draw_wall(double perp_wall, t_data *data, t_ray *ray, int x)
{
	int		wall_height;
	int		limit[2];
	double	texture_pos;
	double	step;
	t_img	*texture;

	wall_height = (int)(data->screen_h / perp_wall);
	limit[0] = -wall_height / 2 + data->screen_h / 2;
	if (limit[0] < 0)
		limit[0] = 0;
	limit[1] = wall_height / 2 + data->screen_h / 2;
	if (limit[1] >= data->screen_h)
		limit[1] = data->screen_h - 1;
	texture = get_texture(data, ray);
	step = 1.0 * texture->height / wall_height;
	texture_pos = (limit[0] - data->screen_h / 2 + wall_height / 2) * step;
	wall_height = get_texture_x(data, ray, perp_wall, texture);
	while (limit[0] <= limit[1])
	{
		put_pixel(data, x, limit[0]++, get_texture_color(texture,
				wall_height, (int)texture_pos % texture->height));
		texture_pos += step;
	}
}
