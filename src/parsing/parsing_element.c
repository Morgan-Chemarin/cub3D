/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:29:09 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/27 16:14:24 by pibreiss         ###   ########.fr       */
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
	texture = &map_data->n_texture;
	if (ft_strcmp(split[0], "SO") == 0)
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
	if (!validate_rgb_array(rgb_values))
	{
		free_split(rgb_values);
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
	char	*rgb_str;

	if (splitlen(split) < 2)
	{
		ft_putstr_fd("Error\nInvalid color definition\n", 2);
		return (0);
	}
	color = &map_data->ceiling_color;
	if (ft_strcmp(split[0], "F") == 0)
		color = &map_data->floor_color;
	if (color->r != -1)
	{
		ft_putstr_fd("Error\nDuplicate color identifier\n", 2);
		return (0);
	}
	rgb_str = join_color_args(split);
	if (!get_rgb_values(rgb_str, color))
	{
		free(rgb_str);
		return (0);
	}
	free(rgb_str);
	map_data->element_count++;
	return (1);
}

int	check_element(char *line, t_map *map_data)
{
	int		status;
	char	**split;

	status = 1;
	split = extract_element_data(line);
	if (!split)
		return (0);
	if (!split[0])
	{
		free_split(split);
		return (1);
	}
	if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0
		|| ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0)
		status = parse_texture(map_data, split);
	else if (ft_strcmp(split[0], "F") == 0 || ft_strcmp(split[0], "C") == 0)
		status = parse_color(map_data, split);
	free_split(split);
	return (status);
}
