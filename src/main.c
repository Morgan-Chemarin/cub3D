/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:38:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/10/03 19:55:03 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map_data;
	int		i;

	if (!check_extension(argc, argv[1]))
		return (1);
	ft_memset(&map_data, 0, sizeof(t_map));
	if (!parse_file(argv[1], &map_data))
		return (1);
	i = 0;
	while (map_data.map && map_data.map[i])
	{
		printf("%s\n", map_data.map[i]);
		i++;
	}
	return (0);
}
