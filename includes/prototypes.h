/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:21:05 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/17 18:36:59 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// check_error
int		check_extension(int argc, char *map_path);

// read_map_file
int		parse_file(char *map_path, t_map *map_data);

// init_data
int		init_data(t_data *data);

// game_loop
int		game_loop(t_data *data);

// events
int		close_window(t_data *data);
int		key_press(int keycode, t_data *data);

// raycasting
void	init_ray(t_data *data, t_ray *ray, int x);

#endif