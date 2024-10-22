/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:24:28 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 19:14:29 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img(t_game *game)
{
	free_wall(game);
	free_player(game);
	free_coin(game);
	free_exit(game);
	free_monster(game);
}

int	exit_game(t_game *game)
{
	destroy_img(game);
	free_tab(game->map->map);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

void	handle_free(t_game *game)
{
	if (game->map)
	{
		free_tab(game->map->map);
		free(game->map);
	}
	if (game->player)
		free_player(game);
	if (game->coin)
		free_coin(game);
	if (game->exit)
		free_exit(game);
	if (game->monster)
		free_monster(game);
	if (game->wall)
		free_wall(game);
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(1);
}
