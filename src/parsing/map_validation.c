/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:38:58 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 00:35:39 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_neighbors(char **map, int y, int x, int map_height)
{
	int	prev_line_len;
	int	next_line_len;

	if (y == 0 || y == map_height - 1)
		return (0);
	if (x == 0 || x >= ft_strlen(map[y]) - 1)
		return (0);
	prev_line_len = ft_strlen(map[y - 1]);
	next_line_len = ft_strlen(map[y + 1]);
	if (x >= prev_line_len || x >= next_line_len)
		return (0);
	if (ft_isspace(map[y - 1][x]) || ft_isspace(map[y + 1][x])
		|| ft_isspace(map[y][x - 1]) || ft_isspace(map[y][x + 1]))
		return (0);
	return (1);
}

int	validate_wall(t_map *map_data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map_data->map && map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			c = map_data->map[i][j];
			if (c == '0')
			{
				if (!check_neighbors(map_data->map, i, j, map_data->map_length))
				{
					ft_putstr_fd("Error\nMap is not closed by walls\n", 2);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
