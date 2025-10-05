/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:19:14 by pibreiss          #+#    #+#             */
/*   Updated: 2025/10/05 15:38:54 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing_element(t_map *map_data)
{
	int	i;
	int	nb_element;

	i = 0;
	nb_element = 0;
	while (map_data->map[i] && nb_element < 6)
	{
		if (!map_data->map[i][0])
		{
			i++;
			continue ;
		}
		if (!check_element(map_data->map[i], map_data))
			return (0);
		nb_element++;
		i++;
	}
	if (nb_element != 6)
	{
		ft_putstr_fd("Error: the number of elements is not correct\n", 2);
		return (0);
	}
	return (1);
}
