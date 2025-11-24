/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:04 by dev               #+#    #+#             */
/*   Updated: 2025/11/24 16:27:21 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map_data)
{
	if (!map_data)
		return ;
	if (map_data->n_texture)
		free(map_data->n_texture);
	if (map_data->s_texture)
		free(map_data->s_texture);
	if (map_data->w_texture)
		free(map_data->w_texture);
	if (map_data->e_texture)
		free(map_data->e_texture);
	if (map_data->map)
		free_split(map_data->map);
}

void	free_textures(t_data *data)
{
	if (data->textures[0].ptr)
		mlx_destroy_image(data->mlx, data->textures[0].ptr);
	if (data->textures[1].ptr)
		mlx_destroy_image(data->mlx, data->textures[1].ptr);
	if (data->textures[2].ptr)
		mlx_destroy_image(data->mlx, data->textures[2].ptr);
	if (data->textures[3].ptr)
		mlx_destroy_image(data->mlx, data->textures[3].ptr);
}

int	free_all(t_data *data)
{
	if (!data)
		return (1);
	free_map(&data->map);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	free_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	// data->running = false;
	exit(0);
	return (0);
}
