/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:29:09 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 00:36:16 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_texture(t_map *map_data, char **split)
{
	char	**texture;

	texture = NULL;
	if (splitlen(split) != 2)
	{
		ft_putstr_fd("Error\nInvalid texture difinition\n", 2);
		return (0);
	}
	if (ft_strcmp(split[0], "NO") == 0)
		texture = &map_data->n_texture;
	else if (ft_strcmp(split[0], "SO") == 0)
		texture = &map_data->s_texture;
	else if (ft_strcmp(split[0], "WE") == 0)
		texture = &map_data->w_texture;
	else if (ft_strcmp(split[0], "EA") == 0)
		texture = &map_data->e_texture;
	if (*texture != NULL)
	{
		ft_putstr_fd("Error\nDuplicate texture identifier\n", 2);
		return (0);
	}
	*texture = ft_strdup(split[1]);
	if (!*texture)
		return (0);
	map_data->element_count++;
	return (1);
}

int	get_rgb_values(char *rgb_definition, t_color *color)
{
	int		r;
	int		g;
	int		b;
	char	**rgb_values;

	rgb_values = ft_split(rgb_definition, ',');
	if (!rgb_values || splitlen(rgb_values) != 3)
	{
		free_split(rgb_values);
		ft_putstr_fd("Error\nInvalid RGB format (must be R,G,B)\n", 2);
		return (0);
	}
	r = ft_atoi(rgb_values[0]);
	g = ft_atoi(rgb_values[1]);
	b = ft_atoi(rgb_values[2]);
	free_split(rgb_values);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_putstr_fd("Error\nRGB values must be in range [0-255]\n", 2);
		return (0);
	}
	color->r = r;
	color->g = g;
	color->b = b;
	return (1);
}

int	parse_color(t_map *map_data, char **split)
{
	t_color	*color;

	color = NULL;
	if (splitlen(split) != 2)
	{
		ft_putstr_fd("Error\nInvalid color definition\n", 2);
		return (0);
	}
	if (ft_strcmp(split[0], "F") == 0)
		color = &map_data->floor_color;
	else if (ft_strcmp(split[0], "C") == 0)
		color = &map_data->ceiling_color;
	if (color->r != -1)
	{
		ft_putstr_fd("Error\nDuplicate color identifier\n", 2);
		return (0);
	}
	if (!get_rgb_values(split[1], color))
		return (0);
	map_data->element_count++;
	return (1);
}

int	check_element(char *line, t_map *map_data)
{
	int		status;
	char	**split;

	status = 1;
	split = ft_split(line, ' ');
	if (!split || !split[0])
	{
		free_split(split);
		return (1);
	}
	if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0
		|| ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0)
		status = parse_texture(map_data, split);
	else if (ft_strcmp(split[0], "F") == 0 || ft_strcmp(split[0], "C") == 0)
		status = parse_color(map_data, split);
	else
	{
		ft_putstr_fd("Error\nInvalid identifier in file:'", 2);
		ft_putstr_fd(split[0], 2);
		ft_putstr_fd("'\n", 2);
		status = 0;
	}
	free_split(split);
	return (status);
}
