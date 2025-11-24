/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:57 by dev               #+#    #+#             */
/*   Updated: 2025/11/24 23:55:52 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x >= data->screen_w || y < 0 || y >= data->screen_h)
		return ;
	dest = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)dest = color;
}

void	draw_background(t_data *d)
{
	int		y;
	int		x;
	int		ceiling_color;
	int		floor_color;
	char	*dst;

	ceiling_color = (d->map.ceiling_color.r << 16)
		| (d->map.ceiling_color.g << 8)
		| d->map.ceiling_color.b;
	floor_color = (d->map.floor_color.r << 16)
		| (d->map.floor_color.g << 8)
		| d->map.floor_color.b;
	y = -1;
	while (++y < d->screen_h)
	{
		x = -1;
		while (++x < d->screen_w)
		{
			dst = d->img.addr + y * d->img.line_len + x * (d->img.bpp / 8);
			if (y < d->screen_h / 2)
				*(int *)dst = ceiling_color;
			else
				*(int *)dst = floor_color;
		}
	}
}
