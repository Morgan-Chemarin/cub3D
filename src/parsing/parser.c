/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:19:14 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 00:35:43 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing_element(t_map *map_data)
{
	int	i;

	i = 0;
	while (map_data->map[i] && map_data->element_count < 6)
	{
		if (!map_data->map[i][0])
		{
			i++;
			continue ;
		}
		if (!check_element(map_data->map[i], map_data))
			return (0);
		i++;
	}
	if (map_data->element_count != 6)
	{
		ft_putstr_fd("Error\nthe number of elements is not correct\n", 2);
		return (0);
	}
	return (parse_map(map_data, i));
}
