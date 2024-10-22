/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:15:24 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/26 13:08:01 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	map_len(char *map_file)
{
	size_t	len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("File descriptor error");
	line = get_next_line(fd, 0);
	if (!line)
		handle_error_gnl(line, fd, "Empty file.");
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	return (len);
}

char	**dup_map(char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = ft_calloc(map_len_y(map) + 1, sizeof(char *));
	if (!map_copy)
		return (free_tab(map_copy), NULL);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			return (free_tab(map), NULL);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_len_x(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
