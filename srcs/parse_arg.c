/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:39:47 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/22 13:06:09 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	is_there_wall(char *map_file, char *line, int fd, size_t i)
{
	size_t	j;

	j = 0;
	while (line[j])
	{
		if (i == 0)
		{
			if (line[j] && line[j] != '1' && j != ft_strlen(line) - 1)
				handle_error_gnl(line, fd, "Map is not surrounded by wall.");
		}
		else if (i == map_len(map_file) - 1)
		{
			if (line[j] && line[j] != '1')
				handle_error_gnl(line, fd, "Map is not surrounded by wall.");
		}
		else if (j == 0 || j == ft_strlen(line) - 2)
		{
			if (line[j] != '1')
				handle_error_gnl(line, fd, "Map is not surrounded by wall.");
		}
		j++;
	}
}

void	map_is_surrounded_by_walls(char *map_file)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		handle_error("File descriptor error.");
	line = get_next_line(fd, 0);
	if (!line)
		handle_error_gnl(line, fd, "Map is empty.");
	i = 0;
	while (line != NULL)
	{
		is_there_wall(map_file, line, fd, i);
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	close(fd);
}

static void	at_least_one(char *line, int *e_count, int *p_count, int *c_count)
{
	size_t	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'E')
			(*e_count)++;
		else if (line[j] == 'P')
			(*p_count)++;
		else if (line[j] == 'C')
			(*c_count)++;
		j++;
	}
}

void	allowed_chars(char *line, int fd)
{
	size_t	j;
	char	*allowed_chars;

	allowed_chars = "10PECM\n\0";
	j = 0;
	while (line[j])
	{
		if (ft_strchr(allowed_chars, line[j]) == NULL)
			handle_error_gnl(line, fd, "Map has invalid characters.");
		j++;
	}
}

void	map_has_valid_chars(char *map_file)
{
	int		fd;
	char	*line;
	int		exit_count;
	int		player_count;
	int		collectible_count;

	exit_count = 0;
	player_count = 0;
	collectible_count = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		handle_error("File descriptor error.");
	line = get_next_line(fd, 0);
	if (!line)
		handle_error_gnl(line, fd, "Map is empty.");
	while (line != NULL)
	{
		allowed_chars(line, fd);
		at_least_one(line, &exit_count, &player_count, &collectible_count);
		free(line);
		line = get_next_line(fd, 0);
	}
	if (exit_count != 1 || player_count != 1 || collectible_count <= 0)
		handle_error_gnl(line, fd, "Map has missing or too many elements.");
	close(fd);
}
