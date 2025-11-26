/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:18:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/26 15:48:11 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' ');
}

void	calculate_map_width(t_map *map_data)
{
	int	y;
	int	max_width;
	int	current_width;

	y = 0;
	max_width = 0;
	while (map_data->map[y])
	{
		current_width = ft_strlen(map_data->map[y]);
		if (current_width > max_width)
			max_width = current_width;
		y++;
	}
	map_data->map_width = max_width;
}

int	get_map_len(char **map, int start)
{
	int	i;
	int	j;

	i = start;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			j = i;
			while (map[j])
			{
				if (map[j][0] != '\0')
				{
					ft_putstr_fd("Error\nInvalid map format\n", 2);
					return (-1);
				}
				j++;
			}
			return (i - start);
		}
		i++;
	}
	return (i - start);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
