/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:25:16 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 19:15:00 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_player2(t_game *game)
{
	game->player->img_player[9] = init_img(game, "./assets/idle_left(1).xpm");
	game->player->img_player[10] = init_img(game, "./assets/idle_left(3).xpm");
	game->player->img_player[11] = init_img(game, "./assets/idle_left(4).xpm");
	game->player->img_player[12] = init_img(game, "./assets/idle_left(5).xpm");
	game->player->img_player[13] = init_img(game, "./assets/idle_left(6).xpm");
	game->player->img_player[14] = init_img(game, "./assets/p_on_e(2).xpm");
	game->player->img_player[15] = init_img(game, "./assets/p_on_e(3).xpm");
	game->player->img_player[16] = init_img(game, "./assets/p_on_e(4).xpm");
	game->player->img_player[17] = init_img(game, "./assets/p_on_e(5).xpm");
	game->player->img_player[18] = init_img(game, "./assets/p_on_e(6).xpm");
	game->player->img_player[19] = init_img(game, "./assets/get_hit(1).xpm");
	game->player->img_player[20] = init_img(game, "./assets/get_hit(2).xpm");
	game->player->img_player[21] = init_img(game, "./assets/get_hit(3).xpm");
	game->player->img_player[22] = init_img(game, "./assets/death(1).xpm");
	game->player->img_player[23] = init_img(game, "./assets/death(2).xpm");
	game->player->img_player[24] = init_img(game, "./assets/death(3).xpm");
	game->player->img_player[25] = init_img(game, "./assets/death(4).xpm");
	game->player->img_player[26] = init_img(game, "./assets/too_noob.xpm");
}

void	init_img_player(t_game *game)
{
	int	i;

	i = 0;
	game->player = init_player(game);
	if (!game->player)
		handle_error("Player initialization failed.");
	game->player->img_player[0] = init_img(game, "./assets/idle_right(1).xpm");
	game->player->img_player[1] = init_img(game, "./assets/idle_right(2).xpm");
	game->player->img_player[2] = init_img(game, "./assets/idle_right(3).xpm");
	game->player->img_player[3] = init_img(game, "./assets/idle_right(4).xpm");
	game->player->img_player[4] = init_img(game, "./assets/idle_right(5).xpm");
	game->player->img_player[5] = init_img(game, "./assets/idle_right(6).xpm");
	game->player->img_player[6] = init_img(game, "./assets/p_on_e(1).xpm");
	game->player->img_player[7] = init_img(game, "./assets/p_on_eopen(1).xpm");
	game->player->img_player[8] = init_img(game, "./assets/idle_left(1).xpm");
	init_img_player2(game);
	while (i < 27)
	{
		if (!game->player->img_player[i])
		{
			free(game->player->img_player[i]);
			free(game->player);
		}
		i++;
	}
}

void	init_img_wall2(t_game *game)
{
	game->wall->img_wall[5] = init_img(game, "./assets/bot.xpm");
	game->wall->img_wall[6] = init_img(game, "./assets/left.xpm");
	game->wall->img_wall[7] = init_img(game, "./assets/right.xpm");
	game->wall->img_wall[8] = init_img(game, "./assets/wood_box.xpm");
	game->wall->img_wall[9] = init_img(game, "./assets/empty_grass.xpm");
	game->wall->img_wall[10] = init_img(game, "./assets/health(0).xpm");
	game->wall->img_wall[11] = init_img(game, "./assets/health(1).xpm");
	game->wall->img_wall[12] = init_img(game, "./assets/health(2).xpm");
	game->wall->img_wall[13] = init_img(game, "./assets/health(3).xpm");
}

void	init_img_wall(t_game *game)
{
	int	i;

	i = 0;
	game->wall = init_wall(game);
	if (!game->wall)
		handle_error("Wall initialization failed.");
	game->wall->img_wall[0] = init_img(game, "./assets/top_left.xpm");
	game->wall->img_wall[1] = init_img(game, "./assets/top_right.xpm");
	game->wall->img_wall[2] = init_img(game, "./assets/bot_left.xpm");
	game->wall->img_wall[3] = init_img(game, "./assets/bot_right.xpm");
	game->wall->img_wall[4] = init_img(game, "./assets/top.xpm");
	init_img_wall2(game);
	while (i < 14)
	{
		if (!game->wall->img_wall[i])
		{
			free(game->wall->img_wall[i]);
			free(game->wall);
		}
		i++;
	}
}
