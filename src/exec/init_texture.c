/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:47:01 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/23 21:22:14 by pibreiss         ###   ########.fr       */
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
	return (1);
}

int	init_textures(t_data *data)
{
	if (!load_texture(data, 0, data->map.n_texture))
		return (0);
	if (!load_texture(data, 1, data->map.s_texture))
		return (0);
	if (!load_texture(data, 2, data->map.w_texture))
		return (0);
	if (!load_texture(data, 3, data->map.e_texture))
		return (0);
	return (1);
}
