/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:56:55 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/26 13:06:52 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*init_img(t_game *game, char *path_image)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (handle_error("Memory allocation failed."), NULL);
	img->img = mlx_xpm_file_to_image(game->mlx, path_image,
			&img->width, &img->height);
	if (!img->img)
		return (free(img), ft_printf("Error\n"),
			ft_printf("Failed to load image: %s\n", path_image),
			ft_printf("mlx_xpm_file_to_image failed.\n"),
			handle_free(game), exit(1), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (free(img->img), free(img),
			handle_error("mlx_get_data_addr failed."), NULL);
	return (img);
}

t_wall	*init_wall(t_game *game)
{
	t_wall	*wall;
	int		i;

	i = 0;
	(void)game;
	wall = ft_calloc(1, sizeof(t_wall));
	if (!wall)
		return (handle_error("Memory allocation failed."), NULL);
	return (wall);
}

t_map	*init_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("File descriptor error.");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		handle_error("Memory allocation failed.");
	map->map = read_map_from_file(fd, map_file);
	close(fd);
	map->width = map_len_x(map->map);
	map->height = map_len_y(map->map);
	return (map);
}

void	init_img_game(t_game *game)
{
	init_img_wall(game);
	init_img_player(game);
	init_img_exit(game);
	init_img_coin(game);
	init_img_monster(game);
}

t_game	*init_game(t_game **game, char *path_file)
{
	(*game) = ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return (handle_error("Memory allocation failed."), NULL);
	(*game)->map = init_map(path_file);
	if (!(*game)->map)
		return (free((*game)),
			handle_error("Map initialization failed."), NULL);
	(*game)->width = map_len_x((*game)->map->map);
	(*game)->height = map_len_y((*game)->map->map);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (free_tab((*game)->map->map), free((*game)->map), free((*game)),
			handle_error("mlx_init failed."), NULL);
	(*game)->win = mlx_new_window((*game)->mlx,
			(*game)->width * 48, (*game)->height * 48, "so_long");
	if (!(*game)->win)
		return (free((*game)->map), free((*game)->mlx),
			free((*game)), handle_error("mlx_new_window failed."), NULL);
	(*game)->last_keypress = time(NULL);
	init_img_game(*game);
	return ((*game));
}
