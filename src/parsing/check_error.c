/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:17:28 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/26 05:38:35 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_extension(int argc, char *map_path)
{
	int	path_size;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nIncorrect number of arguments\n", 2);
		return (0);
	}
	path_size = ft_strlen(map_path);
	if (path_size < 5)
	{
		ft_putstr_fd("Error\nthe argument size must be", 2);
		ft_putstr_fd(" longer than 4 characters\n", 2);
		return (0);
	}
	if (ft_strcmp(map_path + path_size - 4, ".cub") != 0)
	{
		ft_putstr_fd("Error\nThe file name must end with .cub\n", 2);
		return (0);
	}
	return (1);
}

int	validate_rgb_array(char **rgb_values)
{
	if (!rgb_values || splitlen(rgb_values) != 3)
	{
		ft_putstr_fd("Error\nInvalid RGB format (must be R,G,B)\n", 2);
		return (0);
	}
	if (!is_str_digit(rgb_values[0]) || !is_str_digit(rgb_values[1])
		|| !is_str_digit(rgb_values[2]))
	{
		ft_putstr_fd("Error\nInvalid RGB values\n", 2);
		return (0);
	}
	return (1);
}
