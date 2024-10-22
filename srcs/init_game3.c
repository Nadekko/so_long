/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:34:43 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:41 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_exit	*init_exit(t_game *game)
{
	t_exit	*exit;
	int		i;

	i = 0;
	exit = ft_calloc(1, sizeof(t_exit));
	if (!exit)
		return (handle_error("Memory allocation failed."), NULL);
	exit->coord.x = find_element_coord(game->map->map, 'E').x;
	exit->coord.y = find_element_coord(game->map->map, 'E').y;
	return (exit);
}

t_coin	*init_coin(t_game *game)
{
	int	i;

	i = 0;
	game->coin = ft_calloc(1, sizeof(t_coin));
	if (!game->coin)
		handle_error("Memory allocation failed.");
	game->coin->nb_coin = count_elements(game->map->map, 'C');
	game->coin->coord.x = find_element_coord(game->map->map, 'C').x;
	game->coin->coord.y = find_element_coord(game->map->map, 'C').y;
	return (game->coin);
}

t_monster	*init_monster(t_game *game)
{
	game->monster = ft_calloc(1, sizeof(t_monster));
	if (!game->monster)
		handle_error("Memory allocation failed.");
	game->monster->nb_monster = count_elements(game->map->map, 'M');
	game->monster->coord.x = find_element_coord(game->map->map, 'M').x;
	game->monster->coord.y = find_element_coord(game->map->map, 'M').y;
	return (game->monster);
}

t_player	*init_player(t_game *game)
{
	t_player	*player;
	int			i;

	i = 0;
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (handle_error("Memory allocation failed."), NULL);
	player->coord.x = find_element_coord(game->map->map, 'P').x;
	player->coord.y = find_element_coord(game->map->map, 'P').y;
	player->health = NB_LIFE;
	return (player);
}
