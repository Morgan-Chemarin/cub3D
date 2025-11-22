/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:09:55 by dev               #+#    #+#             */
/*   Updated: 2025/11/22 22:47:09 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <mlx.h>

int close_window(t_data *data)
{
	data->running = false;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_A)
		data->input.move_left = true;
	else if (keycode == KEY_D)
		data->input.move_right = true;
	else if (keycode == KEY_S)
		data->input.move_backward = true;
	else if (keycode == KEY_W)
		data->input.move_forward = true;
	else if (keycode == KEY_LEFT)
		data->input.turn_left = true;
	else if (keycode == KEY_RIGHT)
		data->input.turn_right = true;
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		data->input.move_left = false;
	else if (keycode == KEY_D)
		data->input.move_right = false;
	else if (keycode == KEY_S)
		data->input.move_backward = false;
	else if (keycode == KEY_W)
		data->input.move_forward = false;
	else if (keycode == KEY_LEFT)
		data->input.turn_left = false;
	else if (keycode == KEY_RIGHT)
		data->input.turn_right = false;
	return (0);
}
