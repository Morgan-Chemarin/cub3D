/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:13:54 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/29 19:04:51 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*join_color_args(char **split)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (split[i])
	{
		tmp = ft_strjoin(joined, split[i]);
		free(joined);
		joined = tmp;
		i++;
	}
	return (joined);
}

char	**extract_element_data(char *line)
{
	char	*space_ptr;
	char	**split;

	space_ptr = ft_strchr(line, ' ');
	if (!space_ptr)
		return (ft_split(line, ' '));
	split = ft_calloc(3, sizeof(char *));
	if (!split)
		return (NULL);
	split[0] = ft_substr(line, 0, space_ptr - line);
	split[1] = ft_strtrim(space_ptr, " ");
	return (split);
}

int	check_commas(char *rgb_definition)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (rgb_definition[i])
	{
		if (rgb_definition[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	check_color_range(t_color *color)
{
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		ft_putstr_fd("Error\nRGB values must be in range [0-255]\n", 2);
		return (0);
	}
	return (1);
}

int	is_line_empty(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
