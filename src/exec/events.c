/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:09:55 by dev               #+#    #+#             */
/*   Updated: 2025/11/18 18:29:54 by dev              ###   ########.fr       */
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
	if (keycode == 65307)
		close_window(data);
	return (0);
}