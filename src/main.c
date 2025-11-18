/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:38:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/18 19:18:45 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_map	map_data;
	t_data	data;
	// int		i;

	if (!check_extension(argc, argv[1]))
		return (1);
	ft_memset(&map_data, 0, sizeof(t_map));
	if (!parse_file(argv[1], &map_data))
		return (1);
	// i = 0;
	// while (map_data.map && map_data.map[i])
	// {
	// 	printf("%s\n", map_data.map[i]);
	// 	i++;
	// }
	data.map = map_data;
	if (!init_data(&data))
    {
        ft_putstr_fd("Error: MLX initialization failed\n", 2);
        return (1);
    }
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_loop_hook(data.mlx, &game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
