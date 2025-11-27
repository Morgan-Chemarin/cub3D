/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:21:05 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/27 16:15:08 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// * PARSING * //

// check_error
int		check_extension(int argc, char *map_path);
int		validate_rgb_array(char **rgb_values);

// read_map_file
int		parse_file(char *map_path, t_map *map_data);

// parsing_element
int		check_element(char *line, t_map *map_data);

// parsing_element_utils
char	*join_color_args(char **split);
char	**extract_element_data(char *line);

// parser
int		parsing_element(t_map *map_data);

// map_parser
int		parse_map(t_map *map_data, int start_index);

// map_validation
int		validate_wall(t_map *map_data);

// parsing_utils
int		splitlen(char **split);
int		is_valid_char(char c);
void	calculate_map_width(t_map *map_data);
int		get_map_len(char **map, int start);
int		is_str_digit(char *str);

// * EXEC * //

// init_data
int		init_data(t_data *data);

// game_loop
int		game_loop(t_data *data);

// events
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

// raycasting
void	init_ray(t_data *data, t_ray *ray, int x);

// dda
void	dda(t_data *data, t_ray *ray, int x);

// init_texture
int		init_textures(t_data *data);

// texture_handler
void	draw_wall(double perp_wall, t_data *data, t_ray *ray, int x);

// draw.c
void	put_pixel(t_data *data, int x, int y, int color);
void	draw_background(t_data *data);

// * FREE * //
void	free_split(char **split);
void	free_map(t_map *map_data);
void	free_textures(t_data *data);
int		free_all(t_data *data);

#endif