/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:10:20 by pibreiss          #+#    #+#             */
/*   Updated: 2025/11/14 18:47:53 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <fcntl.h>

void	free_map_array(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	list_to_map(t_list *map_list, t_map *map_data)
{
	int		i;
	t_list	*current;

	map_data->map = ft_calloc(ft_lstsize(map_list) + 1, sizeof(char *));
	if (!map_data->map)
		return (0);
	i = 0;
	current = map_list;
	while (current)
	{
		map_data->map[i] = ft_strdup((char *)current->content);
		if (!map_data->map[i])
		{
			free_map_array(map_data->map);
			map_data->map = NULL;
			return (0);
		}
		current = current->next;
		i++;
	}
	return (1);
}

t_list	*read_lines(int fd)
{
	t_list	*head;
	t_list	*new_node;
	char	*line;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_node = ft_lstnew(ft_strtrim(line, "\n"));
		free(line);
		if (!new_node || !new_node->content)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
	}
	return (head);
}

int	parse_file(char *map_path, t_map *map_data)
{
	int		fd;
	t_list	*map_list;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Could not open map file.\n", 2);
		return (0);
	}
	map_list = read_lines(fd);
	close(fd);
	if (!map_list)
	{
		ft_putstr_fd("Error: The map file could not be read\n", 2);
		return (0);
	}
	if (!list_to_map(map_list, map_data))
	{
		ft_lstclear(&map_list, free);
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		return (0);
	}
	ft_lstclear(&map_list, free);
	return (1);
}
