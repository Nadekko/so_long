/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:06:14 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 18:37:56 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_so_long(t_game *game)
{
	int	w_h;
	int	w_w;
	int	img_w;
	int	img_h;

	w_h = map_len_y(game->map->map) * 48;
	w_w = map_len_x(game->map->map) * 48;
	img_w = game->exit->img_exit[9]->width;
	img_h = game->exit->img_exit[9]->height;
	game->coord.x = (w_w - img_w) / 2;
	game->coord.y = (w_h - img_h) / 2;
	mlx_put_image_to_window(game->mlx, game->win,
		game->exit->img_exit[9]->img, game->coord.x, game->coord.y);
	img_interval(game, 1000000);
	exit_game(game);
}

void	player_get_hit(t_game *game)
{
	if (game->map->map[game->player->coord.y][game->player->coord.x] == 'M')
	{
		game->player->health--;
		display_monster(game);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[19]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 100000);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[20]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 100000);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[21]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 100000);
		display_health(game);
	}
}

void	p_on_e(t_game *game)
{
	int	x_e;
	int	y_e;

	x_e = game->exit->coord.x;
	y_e = game->exit->coord.y;
	if (game->coin->nb_coin == 0 && (game->player->coord.x == x_e
			&& game->player->coord.y == y_e))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[7]->img, game->player->coord.x * 48,
			game->player->coord.y * 48);
		mlx_do_sync(game->mlx);
		usleep(100000);
		display_so_long(game);
	}
	else if (game->coin->nb_coin != 0 && (game->player->coord.x == x_e
			&& game->player->coord.y == y_e))
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[6]->img, game->player->coord.x * 48,
			game->player->coord.y * 48);
}
