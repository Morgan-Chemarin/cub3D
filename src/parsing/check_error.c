/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:17:28 by pibreiss          #+#    #+#             */
/*   Updated: 2025/10/03 17:48:43 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_extension(int argc, char *map_path)
{
	int	path_size;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Incorrect number of arguments\n", 2);
		return (0);
	}
	path_size = ft_strlen(map_path);
	if (path_size < 5)
	{
		ft_putstr_fd("Error: the argument size must be", 2);
		ft_putstr_fd(" longer than 4 characters\n", 2);
		return (0);
	}
	if (ft_strcmp(map_path + path_size - 4, ".cub") != 0)
	{
		ft_putstr_fd("Error: The file name must end with .cub\n", 2);
		return (0);
	}
	return (1);
}
