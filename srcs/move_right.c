/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:36 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/22 14:41:25 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_move_right(t_game *game, int *flag)
{
	if (game->map->map[game->player->coord.y][game->player->coord.x + 1] == 'C')
		game->coin->nb_coin--;
	game->map->map[game->player->coord.y][game->player->coord.x] = '0';
	put_img_wall(game, game->player->coord.x, game->player->coord.y, 9);
	game->player->coord.x += 1;
	if (game->map->map[game->player->coord.y][game->player->coord.x] == 'M')
		player_get_hit(game);
	put_img_player(game, game->player->coord.x, game->player->coord.y, 0);
	game->map->map[game->player->coord.y][game->player->coord.x] = 'P';
	game->player->step++;
	if (game->coin->nb_coin == 0 && !(*flag))
	{
		*flag = 1;
		open_the_gate(game);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 8);
	}
	p_on_e(game);
	if (game->coin->nb_coin != 0
		&& ((game->player->coord.x != game->exit->coord.x)
			|| (game->player->coord.y != game->exit->coord.y)))
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 0);
}

void	move_right(t_game *game)
{
	static int	flag;

	if (game->map->map[game->player->coord.y][game->player->coord.x + 1] != '1')
		set_move_right(game, &flag);
}
