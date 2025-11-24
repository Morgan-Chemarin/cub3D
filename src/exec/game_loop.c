/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:03:14 by dev               #+#    #+#             */
/*   Updated: 2025/11/24 23:52:09 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>
#include <math.h>

bool	is_blocked(t_data *data, double x, double y)
{
	int		grid_x;
	int		grid_y;
	int		line_len;
	char	cell;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_y < 0 || grid_y >= data->map.map_length)
		return (true);
	line_len = ft_strlen(data->map.map[grid_y]);
	if (grid_x < 0 || grid_x >= line_len)
		return (true);
	cell = data->map.map[grid_y][grid_x];
	if (cell != '0')
		return (true);
	else
		return (false);
}

void	move_player(t_data *data, double distance_x, double distance_y)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x + distance_x;
	next_y = data->player.y + distance_y;
	if (!is_blocked(data, next_x, data->player.y))
		data->player.x = next_x;
	if (!is_blocked(data, data->player.x, next_y))
		data->player.y = next_y;
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos_a - player->dir_y * sin_a;
	player->dir_y = old_dir_x * sin_a + player->dir_y * cos_a;
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos_a - player->plane_y * sin_a;
	player->plane_y = old_plane_x * sin_a + player->plane_y * cos_a;
}

void	handle_player_input(t_data *data)
{
	t_player	*p;

	p = &data->player;
	if (data->input.move_forward)
		move_player(data, p->dir_x * p->move_speed, p->dir_y * p->move_speed);
	if (data->input.move_backward)
		move_player(data, -p->dir_x * p->move_speed, -p->dir_y * p->move_speed);
	if (data->input.move_right)
		move_player(data, p->plane_x * p->move_speed,
			p->plane_y * p->move_speed);
	if (data->input.move_left)
		move_player(data, -p->plane_x * p->move_speed,
			-p->plane_y * p->move_speed);
	if (data->input.turn_left)
		rotate_player(p, -p->rot_speed);
	if (data->input.turn_right)
		rotate_player(p, p->rot_speed);
}

int	game_loop(t_data *data)
{
	t_ray	ray;
	int		x;

	if (!data->running)
		return (0);
	handle_player_input(data);
	draw_background(data);
	x = 0;
	while (x < data->screen_w)
	{
		init_ray(data, &ray, x);
		dda(data, &ray, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}
