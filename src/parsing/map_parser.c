/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:21:43 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/25 00:00:31 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_player_pos(t_map *map_data, int x, int y)
{
	if (map_data->player_orientation != 0)
	{
		ft_putstr_fd("Error\nMultiple player found\n", 2);
		return (0);
	}
	map_data->player_x = x;
	map_data->player_y = y;
	map_data->player_orientation = map_data->map[y][x];
	map_data->map[y][x] = '0';
	return (1);
}

int	find_player_and_validate_char_map(t_map *map_data)
{
	int	x;
	int	y;

	y = -1;
	map_data->player_orientation = 0;
	while (map_data->map[++y])
	{
		x = -1;
		while (map_data->map[y][++x])
		{
			if (!is_valid_char(map_data->map[y][x]))
			{
				ft_putstr_fd("Error\nInvalid char in map\n", 2);
				return (0);
			}
			if (ft_strchr("NSWE", map_data->map[y][x]))
			{
				if (!set_player_pos(map_data, x, y))
					return (0);
			}
		}
	}
	return (1);
}

int	copy_map(t_map *map_data, char **map_grid, int start_index)
{
	int	j;

	j = 0;
	while (j < map_data->map_length)
	{
		map_grid[j] = ft_strdup(map_data->map[start_index + j]);
		if (!map_grid[j])
		{
			free_split(map_grid);
			return (0);
		}
		j++;
	}
	return (1);
}

int	isolate_map(t_map *map_data, int start_index)
{
	char	**full_file_content;
	char	**map_grid;

	while (map_data->map[start_index] && !map_data->map[start_index][0])
		start_index++;
	if (!map_data->map[start_index])
	{
		ft_putstr_fd("Error\nMap not found\n", 2);
		return (0);
	}
	map_data->map_length = get_map_len(map_data->map, start_index);
	if (map_data->map_length == -1)
		return (0);
	map_grid = ft_calloc(map_data->map_length + 1, sizeof(char *));
	if (!map_grid)
		return (0);
	if (!copy_map(map_data, map_grid, start_index))
		return (0);
	full_file_content = map_data->map;
	map_data->map = map_grid;
	free_split(full_file_content);
	return (1);
}

int	parse_map(t_map	*map_data, int start_index)
{
	if (!isolate_map(map_data, start_index))
		return (0);
	calculate_map_width(map_data);
	if (!find_player_and_validate_char_map(map_data))
		return (0);
	if (map_data->player_orientation == 0)
	{
		ft_putstr_fd("Error\nNo player found\n", 2);
		return (0);
	}
	if (!validate_wall(map_data))
		return (0);
	return (1);
}
