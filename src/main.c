/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:38:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 00:34:51 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_map	map_data;
	t_data	data;

	if (!check_extension(argc, argv[1]))
		return (1);
	ft_memset(&map_data, 0, sizeof(t_map));
	ft_memset(&data, 0, sizeof(t_data));
	map_data.floor_color.r = -1;
	map_data.ceiling_color.r = -1;
	if (!parse_file(argv[1], &map_data))
		return (1);
	if (!parsing_element(&map_data))
	{
		free_all(&map_data);
		return (1);
	}
	data.map = map_data;
	if (!init_data(&data))
    {
        ft_putstr_fd("Error\nMLX initialization failed\n", 2);
        return (1);
    }
	if (!init_textures(&data))
		return (1);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 3, 1L<<1, key_release, &data);
	mlx_loop_hook(data.mlx, &game_loop, &data);
	mlx_loop(data.mlx);
	free_all(&map_data);
	return (0);
}
