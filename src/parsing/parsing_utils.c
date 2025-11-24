/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:18:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 15:48:48 by dev              ###   ########.fr       */
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
