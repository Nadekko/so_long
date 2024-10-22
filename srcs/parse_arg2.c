/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:20:53 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/22 13:06:50 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*supp_line_break(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

char	**read_map_from_file(int fd, char *map_file)
{
	size_t	i;
	char	*line;
	char	**map;

	i = 0;
	map = ft_calloc(map_len(map_file) + 1, sizeof(char *));
	if (!map)
		handle_error("Malloc failed.");
	line = get_next_line(fd, 0);
	if (!line)
		handle_error_gnl(line, fd, "Empty file.");
	while (line)
	{
		map[i] = ft_strdup(supp_line_break(line));
		if (!map[i])
			return (free_tab(map),
				handle_error_gnl(line, fd, "Malloc failed."), NULL);
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	map_has_valid_path(char *map_file)
{
	int		fd;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("File descriptor error.");
	map = read_map_from_file(fd, map_file);
	close(fd);
	if (map)
	{
		if (map_len_x(map) > WIDTH || map_len_y(map) > HEIGHT)
		{
			free_tab(map);
			handle_error("Map is too big.");
		}
		parse_flood_map(map);
		free_tab(map);
	}
}

void	map_is_rectangular(char *map_file)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	len;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("File descriptor error.");
	line = get_next_line(fd, 0);
	if (!line)
		handle_error_gnl(line, fd, "Empty file.");
	len = ft_strlen(line);
	i = 1;
	while (line)
	{
		if ((i != map_len(map_file) && ft_strlen(line) != len)
			|| (i == map_len(map_file) && ft_strlen(line) != len - 1))
			handle_error_gnl(line, fd, "Map is not rectangular.");
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	free(line);
	close(fd);
}

void	parse_arg(int ac, char **av)
{
	char	*map_file;

	if (ac != 2)
		handle_error("Invalid number of arguments.");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		handle_error("Invalid file extension.");
	map_file = av[1];
	map_is_rectangular(map_file);
	map_is_surrounded_by_walls(map_file);
	map_has_valid_chars(map_file);
	map_has_valid_path(map_file);
}

// static void	map_has_valid_size(char *map_file)
// {
// 	int fd;
// 	char **map;
// 	int map_width;
// 	int map_height;

// 	fd = open(map_file, O_RDONLY);
// 	if (fd < 0)
// 		handle_error("File descriptor error.");
// 	map = read_map_from_file(fd, map_file);
// 	close(fd);
// 	map_width = map_len_x(map);
// 	map_height = map_len_y(map);
// 	if (map_width > WIDTH || map_height > HEIGHT)
// 		handle_error("Map is too big.");
// 	if (map)
// 		free_tab(map);
// }