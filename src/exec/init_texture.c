/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:47:01 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:17 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <mlx.h>

int	load_texture(t_data *data, int idx, char *path)
{
	data->textures[idx].ptr = mlx_xpm_file_to_image(data->mlx, path,
			&data->textures[idx].width, &data->textures[idx].height);
	if (!data->textures[idx].ptr)
	{
		ft_putstr_fd("Error\nCould not load texture\n", 2);
		return (0);
	}
	data->textures[idx].addr = mlx_get_data_addr(data->textures[idx].ptr,
			&data->textures[idx].bpp, &data->textures[idx].line_len,
			&data->textures[idx].endian);
	if (!data->textures[idx].addr)
	{
		ft_putstr_fd("Error\nCould not load texture\n", 2);
		return (0);
	}
	return (1);
}

int	init_textures(t_data *data)
{
	char	*paths[4];
	int		i;

	paths[0] = data->map.n_texture;
	paths[1] = data->map.s_texture;
	paths[2] = data->map.w_texture;
	paths[3] = data->map.e_texture;
	i = 0;
	while (i < 4)
	{
		if (!load_texture(data, i, paths[i]))
		{
			while (--i >= 0)
			{
				if (data->textures[i].ptr)
					mlx_destroy_image(data->mlx, data->textures[i].ptr);
				data->textures[i].ptr = NULL;
			}
			return (0);
		}
		i++;
	}
	return (1);
}
