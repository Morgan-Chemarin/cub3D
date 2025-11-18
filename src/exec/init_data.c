/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:46:26 by dev               #+#    #+#             */
/*   Updated: 2025/11/18 18:29:29 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>
#include <mlx.h>

static void	init_player(t_data *data)
{
	data->player.x = data->map.player_x + 0.5;
	data->player.y = data->map.player_y + 0.5;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
	if (data->map.player_orientation == 'N')
	{
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (data->map.player_orientation == 'S')
	{
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (data->map.player_orientation == 'W')
	{
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	else if (data->map.player_orientation == 'E')
	{
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.05;
}


int	init_data(t_data *data)
{
	data->screen_w = 1024;
	data->screen_h = 768;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->screen_w, data->screen_h, "cub3D");
	if (!data->win)
		return (0);
	data->img.ptr = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	if (!data->img.ptr)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.ptr,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	init_player(data);
	data->running = true;
	return (1);
}
