/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:21:05 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/15 19:09:36 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// check_error
int		check_extension(int argc, char *map_path);

// read_map_file
int		parse_file(char *map_path, t_map *map_data);

// parsing_element
void	free_split(char **split);
int		check_element(char *line, t_map *map_data);

// parser
int		parsing_element(t_map *map_data);

// map_parser
int		parse_map(t_map	*map_data, int start_index);

// map_validation
int		validate_wall(t_map *map_data);

// parsing_utils
void	free_split(char **split);
int		splitlen(char **split);
int		is_valid_char(char c);
void	calculate_map_width(t_map *map_data);

#endif