/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:46:18 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 18:23:51 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_the_gate(t_game *game)
{
	static int	flag;

	if (game->coin->nb_coin == 0 && !flag)
	{
		flag = 1;
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 1);
		img_interval(game, 79999);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 2);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 3);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 4);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 5);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 6);
		img_interval(game, 79999);
		put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 7);
	}
	put_img_exit(game, game->exit->coord.x, game->exit->coord.y, 8);
	img_interval(game, 59999);
}

void	display_too_noob(t_game *game)
{
	int	w_h;
	int	w_w;
	int	img_w;
	int	img_h;

	w_h = map_len_y(game->map->map) * 48;
	w_w = map_len_x(game->map->map) * 48;
	img_w = game->player->img_player[26]->width;
	img_h = game->player->img_player[26]->height;
	game->coord.x = (w_w - img_w) / 2;
	game->coord.y = (w_h - img_h) / 2;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img_player[26]->img, game->coord.x, game->coord.y);
	img_interval(game, 1000000);
	exit_game(game);
}

void	display_death(t_game *game)
{
	if (game->player->health == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[10]->img, (game->map->width - 2) * 48, 0);
		img_interval(game, 99999);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[22]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 99999);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[23]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 99999);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[24]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 99999);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img_player[25]->img,
			game->player->coord.x * 48, game->player->coord.y * 48);
		img_interval(game, 99999);
		display_too_noob(game);
	}
}

void	display_health(t_game *game)
{
	if (game->player->health == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[13]->img, (game->map->width - 2) * 48, 0);
	if (game->player->health == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[12]->img, (game->map->width - 2) * 48, 0);
	else if (game->player->health == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[11]->img, (game->map->width - 2) * 48, 0);
	display_death(game);
}
