/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:57 by dev               #+#    #+#             */
/*   Updated: 2025/11/24 15:36:32 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*destination;

	if (x < 0 || x >= data->screen_w || y < 0 || y >= data->screen_h)
		return ;
	destination = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)destination = color;
}

void	draw_background(t_data *data)
{
	int		y;
	int		x;
	int		ceiling_color;
	int		floor_color;
	char	*dst;

	ceiling_color = (data->map.ceiling_color.r << 16)
		| (data->map.ceiling_color.g << 8)
		| data->map.ceiling_color.b;
	floor_color = (data->map.floor_color.r << 16)
		| (data->map.floor_color.g << 8)
		| data->map.floor_color.b;
	y = 0;
	while (y < data->screen_h)
	{
		x = 0;
		while (x < data->screen_w)
		{
			dst = data->img.addr + y * data->img.line_len + x * (data->img.bpp / 8);
			if (y < data->screen_h / 2)
				*(int *)dst = ceiling_color;
			else
				*(int *)dst = floor_color;
			x++;
		}
		y++;
	}
}
