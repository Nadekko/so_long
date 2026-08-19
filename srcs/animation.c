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

# define MONSTER_AXIS_X 0
# define MONSTER_AXIS_Y 1
# define MONSTER_AXIS MONSTER_AXIS_X
# define MONSTER_MOVE_DELAY_MS 400

static int		*monster_dirs;
static int		monster_dir_count;
static long long	monster_last_move_ms;

static char	**copy_monster_map(char **map)
{
	char	**copy;
	int		row;
	int		rows;

	row = 0;
	rows = map_len_y(map);
	copy = ft_calloc(rows + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	while (row < rows)
	{
		copy[row] = ft_strdup(map[row]);
		if (!copy[row])
		{
			free_tab(copy);
			return (NULL);
		}
		row++;
	}
	copy[row] = NULL;
	return (copy);
}

static int	monster_can_move(char tile)
{
	return (tile == '0' || tile == 'P');
}

static int	inside_map(t_game *game, int x, int y)
{
	return (x >= 0 && y >= 0 && x < game->map->width && y < game->map->height);
}

static int	init_monster_dirs(int count)
{
	int	index;

	if (monster_dirs)
		free(monster_dirs);
	monster_dirs = ft_calloc(count, sizeof(int));
	if (!monster_dirs)
		return (0);
	index = 0;
	while (index < count)
	{
		if (index % 2 == 0)
			monster_dirs[index] = 1;
		else
			monster_dirs[index] = -1;
		index++;
	}
	monster_dir_count = count;
	return (1);
}

int	monster_sprite_base(int index)
{
	if (index < 0)
		return (0);
	if (!monster_dirs || index >= monster_dir_count)
		return (0);
	if (monster_dirs[index] < 0)
		return (4);
	return (0);
}

int	move_monsters(t_game *game)
{
	char			**new_map;
	int				count;
	int				idx;
	int				i;
	int				j;
	int				hit_player;
	long long		now;
	int				direction;
	int				next_x;
	int				next_y;
	int				step_x;
	int				step_y;

	count = count_elements(game->map->map, 'M');
	if (count <= 0)
		return (0);
	if (count != monster_dir_count && !init_monster_dirs(count))
		return (handle_error("Monster direction allocation failed."), 0);
	now = get_time_ms();
	if (monster_last_move_ms != 0 && now - monster_last_move_ms < MONSTER_MOVE_DELAY_MS)
		return (0);
	monster_last_move_ms = now;
	new_map = copy_monster_map(game->map->map);
	if (!new_map)
		return (handle_error("Monster map copy failed."), 0);
	hit_player = 0;
	idx = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'M')
			{
				direction = monster_dirs[idx];
				step_x = 0;
				step_y = 0;
				if (MONSTER_AXIS == MONSTER_AXIS_X)
					step_x = direction;
				else
					step_y = direction;
				next_x = j + step_x;
				next_y = i + step_y;
				if (inside_map(game, next_x, next_y)
					&& monster_can_move(game->map->map[next_y][next_x])
					&& new_map[next_y][next_x] != 'M')
				{
					new_map[i][j] = '0';
					new_map[next_y][next_x] = 'M';
					if (game->player->coord.x == next_x
						&& game->player->coord.y == next_y)
						hit_player = 1;
				}
				else
				{
					monster_dirs[idx] *= -1;
					direction = monster_dirs[idx];
					step_x = 0;
					step_y = 0;
					if (MONSTER_AXIS == MONSTER_AXIS_X)
						step_x = direction;
					else
						step_y = direction;
					next_x = j + step_x;
					next_y = i + step_y;
					if (inside_map(game, next_x, next_y)
						&& monster_can_move(game->map->map[next_y][next_x])
						&& new_map[next_y][next_x] != 'M')
					{
						new_map[i][j] = '0';
						new_map[next_y][next_x] = 'M';
						if (game->player->coord.x == next_x
							&& game->player->coord.y == next_y)
							hit_player = 1;
					}
				}
				idx++;
			}
			j++;
		}
		i++;
	}
	free_tab(game->map->map);
	game->map->map = new_map;
	return (hit_player);
}

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

// int	animation_monster(t_game *game)
// {
// 	t_monster	*tab;
// 	int			count_monster;

// 	count_monster = count_elements(game->map->map, 'M');
// 	tab = init_monster_tab(count_monster);
// 	if (!tab)
// 		return (handle_error("Malloc Failed"), 1);
// 	fill_monster_tab(game, tab);
// 	animate_monsters(game, tab, count_monster);
// 	free(tab);
// 	return (0);
// }
