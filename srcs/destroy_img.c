/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:10:41 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 18:12:43 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		if (game->wall->img_wall[i])
		{
			mlx_destroy_image(game->mlx, game->wall->img_wall[i]->img);
			free(game->wall->img_wall[i]);
		}
		i++;
	}
	if (game->wall)
		free(game->wall);
}

void	free_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 27)
	{
		if (game->player->img_player[i])
		{	
			mlx_destroy_image(game->mlx, game->player->img_player[i]->img);
			free(game->player->img_player[i]);
		}
		i++;
	}
	if (game->player)
		free(game->player);
}

void	free_coin(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->coin->img_coin[i])
		{
			mlx_destroy_image(game->mlx, game->coin->img_coin[i]->img);
			free(game->coin->img_coin[i]);
		}
		i++;
	}
	if (game->coin)
		free(game->coin);
}

void	free_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->exit->img_exit[i])
		{
			mlx_destroy_image(game->mlx, game->exit->img_exit[i]->img);
			free(game->exit->img_exit[i]);
		}
		i++;
	}
	if (game->exit)
		free(game->exit);
}

void	free_monster(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->monster->img_monster[i])
		{
			mlx_destroy_image(game->mlx, game->monster->img_monster[i]->img);
			free(game->monster->img_monster[i]);
		}
		i++;
	}
	if (game->monster)
		free(game->monster);
}
