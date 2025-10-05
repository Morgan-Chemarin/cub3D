/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:38:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/10/05 15:28:05 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map_data;

	if (!check_extension(argc, argv[1]))
		return (1);
	ft_memset(&map_data, 0, sizeof(t_map));
	map_data.floor_color.r = -1;
	map_data.ceiling_color.r = -1;
	if (!parse_file(argv[1], &map_data))
		return (1);
	if (!parsing_element(&map_data))
	{
		//free_all
		return (1);
	}
	return (0);
}
