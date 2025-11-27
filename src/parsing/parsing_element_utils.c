/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:13:54 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/27 16:23:22 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*join_color_args(char **split)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (split[i])
	{
		tmp = ft_strjoin(joined, split[i]);
		free(joined);
		joined = tmp;
		i++;
	}
	return (joined);
}

char	**extract_element_data(char *line)
{
	char	*space_ptr;
	char	**split;

	space_ptr = ft_strchr(line, ' ');
	if (!space_ptr)
		return (ft_split(line, ' '));
	split = ft_calloc(3, sizeof(char *));
	if (!split)
		return (NULL);
	split[0] = ft_substr(line, 0, space_ptr - line);
	split[1] = ft_strtrim(space_ptr, " ");
	return (split);
}
