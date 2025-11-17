/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:18:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/17 18:36:49 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

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

void	free_all(t_map *map_data)
{
	if (!map_data)
		return ;
	if (map_data->n_texture)
		free(map_data->n_texture);
	if (map_data->s_texture)
		free(map_data->s_texture);
	if (map_data->w_texture)
		free(map_data->w_texture);
	if (map_data->e_texture)
		free(map_data->e_texture);
	if (map_data->map)
		free_split(map_data->map);
}
