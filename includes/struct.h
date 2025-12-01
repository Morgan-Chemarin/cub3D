/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:37:17 by pibreiss          #+#    #+#             */
/*   Updated: 2025/12/01 17:32:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**map;
	int		element_count;
	int		map_length;
	int		map_width;
	int		player_x;
	int		player_y;
	char	player_orientation;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		grid_x;
	int		grid_y;
	double	total_dist_x;
	double	total_dist_y;
	double	dist_step_x;
	double	dist_step_y;
	int		step_dir_x;
	int		step_dir_y;
	int		wall_hit;
	int		axis_orientation;
}	t_ray;

typedef struct s_input
{
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	turn_left;
	bool	turn_right;
}	t_input;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		textures[4];
	t_map		map;
	t_player	player;
	t_input		input;
	int			screen_w;
	int			screen_h;
}	t_data;

#endif