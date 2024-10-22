/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:45 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 18:37:40 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_on_exit_start_animation(t_game *game)
{
	int	x_p;
	int	y_p;

	x_p = game->player->coord.x;
	y_p = game->player->coord.y;
	if (kbhit())
		game->last_keypress = time(NULL);
	put_img_player(game, x_p, y_p, 6);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 14);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 15);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 16);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 17);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 18);
	img_interval(game, 100000);
	put_img_player(game, x_p, y_p, 6);
}

int	check_idle_and_start_animation(t_game *game, int flag, int x_p, int y_p)
{
	if (is_idle(game, 2) && flag == 1)
	{
		if (kbhit())
			game->last_keypress = time(NULL);
		put_img_player(game, x_p, y_p, 0);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 1);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 2);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 3);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 4);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 5);
		img_interval(game, 100000);
		put_img_player(game, x_p, y_p, 0);
	}
	else if (is_idle(game, 2) && flag == 2)
		player_on_exit_start_animation(game);
	return (0);
}

void	display_collectible(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->coin->img_coin[0]->img, j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	display_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (i == game->exit->coord.y
				&& j == game->exit->coord.x && game->coin->nb_coin > 0)
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit->img_exit[0]->img, j * 48, i * 48);
			else if (i == game->exit->coord.y
				&& j == game->exit->coord.x && game->coin->nb_coin == 0)
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit->img_exit[8]->img,
					game->exit->coord.x * 48, game->exit->coord.y * 48);
			j++;
		}
		i++;
	}
}
