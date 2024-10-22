/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:20:59 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/26 13:21:44 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	anim_monster(t_game *game, int x, int y)
{
	put_img_monster(game, x, y, 0);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 1);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 2);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 3);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 4);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 5);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 6);
	img_interval(game, 19999);
	put_img_monster(game, x, y, 7);
	mlx_do_sync(game->mlx);
}

t_monster	*init_monster_tab(int count_monster)
{
	t_monster	*tab;

	tab = ft_calloc(count_monster, sizeof(t_monster));
	if (!tab)
		return (handle_error("Malloc Failed"), NULL);
	return (tab);
}

void	fill_monster_tab(t_game *game, t_monster *tab)
{
	int	i;
	int	j;
	int	monster;

	i = 0;
	monster = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'M')
			{
				tab[monster].coord.x = j;
				tab[monster].coord.y = i;
				monster++;
			}
			j++;
		}
		i++;
	}
}

void	animate_monsters(t_game *game, t_monster *tab, int count_monster)
{
	int	i;

	i = 0;
	while (i < count_monster)
	{
		anim_monster(game, tab[i].coord.x, tab[i].coord.y);
		i++;
		count_monster = count_elements(game->map->map, 'M');
	}
}

int	animation_monster(t_game *game)
{
	t_monster	*tab;
	int			count_monster;

	count_monster = count_elements(game->map->map, 'M');
	tab = init_monster_tab(count_monster);
	if (!tab)
		return (handle_error("Malloc Failed"), 1);
	fill_monster_tab(game, tab);
	animate_monsters(game, tab, count_monster);
	free(tab);
	return (0);
}

/*NORMINETTE*/
// int	animation_monster(t_game *game)
// {
// 	int			i;
// 	int			j;
// 	int			monster;
// 	t_monster	tab[game->monster->nb_monster];

// 	i = 0;
// 	monster = 0;
// 	while (i < game->map->height)
// 	{
// 		j = 0;
// 		while (j++ < game->map->width)
// 		{
// 			if (game->map->map[i][j] == 'M')
// 			{
// 				tab[monster].coord.x = j;
// 				tab[monster].coord.y = i;
// 				monster++;
// 			}
// 		}
// 		i++;
// 	}
// 	i = -1;
// 	while (i++ < game->monster->nb_monster)
// 		anim_monster(game, tab[i].coord.x, tab[i].coord.y);
// 	return (0);
// }
