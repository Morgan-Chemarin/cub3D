/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:03:14 by dev               #+#    #+#             */
/*   Updated: 2025/11/18 23:17:23 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>

static void draw_test_pattern(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < data->screen_w)
	{
		init_ray(data, &ray, x);
		dda(data, &ray, x);
		x++;
	}
}

int	game_loop(t_data *data)
{
	if (!data->running)
		return (0);
	// afficher plafond et sol avant mur ( peut etre direct dans drawtestpattern)
	draw_test_pattern(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}