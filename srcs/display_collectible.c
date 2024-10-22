/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:45:14 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:05 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	anim_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->coin->img_coin[0]->img, x * 48, y * 48);
	img_interval(game, 10000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->coin->img_coin[1]->img, x * 48, y * 48);
	img_interval(game, 10000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->coin->img_coin[2]->img, x * 48, y * 48);
	img_interval(game, 10000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->coin->img_coin[3]->img, x * 48, y * 48);
}

t_coin	*init_tab(int count_coin)
{
	t_coin	*tab;

	tab = ft_calloc(count_coin, sizeof(t_coin));
	if (!tab)
		return (handle_error("Malloc Failed"), NULL);
	return (tab);
}

void	fill_tab(t_game *game, t_coin *tab)
{
	int	i;
	int	j;
	int	coin;

	i = 0;
	coin = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'C')
			{
				tab[coin].coord.x = j;
				tab[coin].coord.y = i;
				coin++;
			}
			j++;
		}
		i++;
	}
}

void	animate_coin(t_game *game, t_coin *tab, int count_coin)
{
	int	i;

	i = 0;
	while (i < count_coin)
	{
		anim_collectible(game, tab[i].coord.x, tab[i].coord.y);
		i++;
		count_coin = count_elements(game->map->map, 'C');
	}
}

int	animation_collectible(t_game *game)
{
	int		count_coin;
	t_coin	*tab;

	count_coin = count_elements(game->map->map, 'C');
	tab = init_tab(count_coin);
	if (!tab)
		return (handle_error("Malloc Failed"), 1);
	fill_tab(game, tab);
	animate_coin(game, tab, count_coin);
	free(tab);
	return (0);
}

/*NORMINETTE*/
// int	animation_collectible(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	int		coin;
// 	int		count_coin;
// 	t_coin	*tab;

// 	count_coin = count_elements(game->map->map, 'C');
// 	tab = ft_calloc(count_coin, sizeof(t_coin));
// 	if (!tab)
// 		return (handle_error("Malloc Failed"), 1);
// 	i = 0;
// 	coin = 0;
// 	while (i < game->map->height)
// 	{
// 		j = 0;
// 		while (j < game->map->width)
// 		{
// 			if (game->map->map[i][j] == 'C')
// 			{
// 				tab[coin].coord.x = j;
// 				tab[coin].coord.y = i;
// 				coin++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < count_coin)
// 	{
// 		anim_collectible(game, tab[i].coord.x, tab[i].coord.y);
// 		i++;
// 		count_coin = count_elements(game->map->map, 'C');
// 	}
// 	free(tab);
// 	return (0);
// }