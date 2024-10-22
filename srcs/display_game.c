/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:21:43 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:08 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// width(largeur) est associé à l'axe des x (horizontal). = j
// height(hauteur) est associé à l'axe des y (vertical). = i

#include "../include/so_long.h"

void	display_wall_floor2(t_game *game, int j, int i)
{
	if (i == game->map->height - 1 && j == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[2]->img, j * 48, i * 48);
	else if (i == 0 && j > 0 && j < game->map->width - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[4]->img, j * 48, i * 48);
	else if (i == game->map->height - 1 && j > 0 && j < game->map->width - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[5]->img, j * 48, i * 48);
	else if (i > 0 && i < game->map->height - 1 && j == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[7]->img, j * 48, i * 48);
	else if (i > 0 && i < game->map->height - 1 && j == game->map->width - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[6]->img, j * 48, i * 48);
	else if (game->map->map[i][j] == '1' && i > 0 && i < game->map->height - 1
		&& j > 0 && j < game->map->width - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[8]->img, j * 48, i * 48);
	else if (game->map->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->img_wall[9]->img, j * 48, i * 48);
}

void	display_wall_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall->img_wall[0]->img, j * 48, i * 48);
			else if (i == 0 && j == game->map->width - 1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall->img_wall[1]->img, j * 48, i * 48);
			else if (i == game->map->height - 1 && j == game->map->width - 1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall->img_wall[3]->img, j * 48, i * 48);
			display_wall_floor2(game, j, i);
			j++;
		}
		i++;
	}
}

void	display_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->player->img_player[0]->img,
				game->player->coord.x * 48, game->player->coord.y * 48);
			mlx_loop_hook(game->mlx, check_idle_and_start_animation, game);
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_monster(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'M')
				mlx_put_image_to_window(game->mlx, game->win,
					game->monster->img_monster[0]->img, j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	display_game(t_game *game)
{
	display_wall_floor(game);
	display_exit(game);
	display_player(game);
	display_collectible(game);
	display_monster(game);
	display_health(game);
	set_moove(game);
	print_moove(game);
	mlx_loop(game->mlx);
}
