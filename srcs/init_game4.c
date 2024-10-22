/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:31:53 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 18:12:00 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_exit(t_game *game)
{
	int	i;

	i = 0;
	game->exit = init_exit(game);
	if (!game->exit)
		handle_error("Exit initialization failed.");
	game->exit->img_exit[0] = init_img(game, "./assets/door(1).xpm");
	game->exit->img_exit[1] = init_img(game, "./assets/door(2).xpm");
	game->exit->img_exit[2] = init_img(game, "./assets/door(3).xpm");
	game->exit->img_exit[3] = init_img(game, "./assets/door(4).xpm");
	game->exit->img_exit[4] = init_img(game, "./assets/door(5).xpm");
	game->exit->img_exit[5] = init_img(game, "./assets/door(6).xpm");
	game->exit->img_exit[6] = init_img(game, "./assets/door(7).xpm");
	game->exit->img_exit[7] = init_img(game, "./assets/door(8).xpm");
	game->exit->img_exit[8] = init_img(game, "./assets/door(9).xpm");
	game->exit->img_exit[9] = init_img(game, "./assets/so_long.xpm");
	while (i < 10)
	{
		if (!game->exit->img_exit[i])
		{
			free(game->exit->img_exit[i]);
			free(game->exit);
		}
		i++;
	}
}

void	init_img_coin(t_game *game)
{
	t_coin	*coin;
	int		i;

	i = 0;
	coin = init_coin(game);
	if (!coin)
		handle_error("Coin initialization failed.");
	game->coin->img_coin[0] = init_img(game, "./assets/coin(1).xpm");
	game->coin->img_coin[1] = init_img(game, "./assets/coin(2).xpm");
	game->coin->img_coin[2] = init_img(game, "./assets/coin(3).xpm");
	game->coin->img_coin[3] = init_img(game, "./assets/coin(4).xpm");
	while (i < 4)
	{
		if (!game->coin->img_coin[i])
		{
			free(game->coin->img_coin[i]);
			free(game->coin);
		}
		i++;
	}
}

void	init_img_monster(t_game *game)
{
	t_monster	*monster;
	int			i;

	i = 0;
	monster = init_monster(game);
	if (!monster)
		handle_error("Monster initialization failed.");
	monster->img_monster[0] = init_img(game, "./assets/m_right(1).xpm");
	monster->img_monster[1] = init_img(game, "./assets/m_right(2).xpm");
	monster->img_monster[2] = init_img(game, "./assets/m_right(3).xpm");
	monster->img_monster[3] = init_img(game, "./assets/m_right(4).xpm");
	monster->img_monster[4] = init_img(game, "./assets/m_left(1).xpm");
	monster->img_monster[5] = init_img(game, "./assets/m_left(2).xpm");
	monster->img_monster[6] = init_img(game, "./assets/m_left(3).xpm");
	monster->img_monster[7] = init_img(game, "./assets/m_left(4).xpm");
	while (i < 8)
	{
		if (!monster->img_monster[i])
		{
			free(monster->img_monster[i]);
			free(monster);
		}
		i++;
	}
}
