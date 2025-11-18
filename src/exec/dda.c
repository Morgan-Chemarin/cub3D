/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:32:01 by dev               #+#    #+#             */
/*   Updated: 2025/11/18 23:16:51 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>

void	dda(t_data *data, t_ray *ray, int x)
{
    
	// avancer le rayon jusqua toucher un mur ( dda )
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (ray->map_y < 0 || ray->map_y >= data->map.map_length
            || ray->map_x < 0 || ray->map_x >= data->map.map_width)
            return;
        if (data->map.map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
	// un truc chelou de distorsion et doeil de poisson ( le calcul de la distance)
	// dessiner du point a au point b
    (void)x;
}
