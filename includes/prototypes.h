/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:21:05 by pibreiss          #+#    #+#             */
/*   Updated: 2025/10/05 14:49:08 by pibreiss         ###   ########.fr       */
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

#endif