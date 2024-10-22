/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:57:42 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/23 12:51:27 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_moove(t_game *game)
{
	char	*step;

	step = ft_itoa(game->player->step);
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall->img_wall[5]->img, 48, (game->height * 48) - 48);
	mlx_string_put(game->mlx, game->win, 16,
		(game->height * 48) - 19, 0xC0DCC0, "STEP : ");
	mlx_string_put(game->mlx, game->win, 70,
		(game->height * 48) - 19, 0xC0DCC0, step);
	free(step);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_up(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	else if (keycode == 97 || keycode == 65361)
		move_left(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
	print_moove(game);
	game->last_keypress = time(NULL);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119 || keycode == 65362)
		return (0);
	else if (keycode == 115 || keycode == 65364)
		return (0);
	else if (keycode == 97 || keycode == 65361)
		return (0);
	else if (keycode == 100 || keycode == 65363)
		return (0);
	return (1);
}

int	animation(t_game *game)
{
	int	flag;
	int	x_p;
	int	y_p;

	flag = 0;
	x_p = game->player->coord.x;
	y_p = game->player->coord.y;
	if (game->player->coord.x != game->exit->coord.x
		|| game->player->coord.y != game->exit->coord.y)
		flag = 1;
	else if (game->player->coord.x == game->exit->coord.x
		&& game->player->coord.y == game->exit->coord.y)
		flag = 2;
	animation_collectible(game);
	animation_monster(game);
	check_idle_and_start_animation(game, flag, x_p, y_p);
	return (0);
}

void	set_moove(t_game *game)
{
	mlx_loop_hook(game->mlx, animation, game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
