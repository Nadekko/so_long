/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:43:53 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 17:45:33 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_idle(t_game *game, int seconds)
{
	time_t	current_time;

	current_time = time(NULL);
	return ((current_time - game->last_keypress) > seconds);
}

void	put_img_player(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img_player[i]->img, x * 48, y * 48);
}

void	put_img_monster(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->monster->img_monster[i]->img, x * 48, y * 48);
}

void	put_img_exit(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->exit->img_exit[i]->img, x * 48, y * 48);
}

void	put_img_wall(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall->img_wall[i]->img, x * 48, y * 48);
}
