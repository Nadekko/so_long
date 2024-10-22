/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flood_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:20:38 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/20 17:45:26 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Cette fonction transforme une case en 'W' (eau)
// si elle est soit '0', 'C' ou 'E'.
// Elle retourne 1 si la case a été transformée, sinon 0.
static char	water_tile(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
	{
		map[i][j] = 'W';
		return (1);
	}
	return (0);
}

// Cette fonction propage l'eau depuis une case aux cases adjacentes.
// Elle utilise la fonction water_tile
// pour déterminer si une case doit être transformée en eau.
// Elle retourne le nombre de cases qui ont été transformées.
static int	spread_water(char **map, int i, int j)
{
	int	been_wet;

	been_wet = 0;
	if (water_tile(map, i - 1, j))
		been_wet++;
	if (water_tile(map, i, j - 1))
		been_wet++;
	if (water_tile(map, i + 1, j))
		been_wet++;
	if (water_tile(map, i, j + 1))
		been_wet++;
	return (been_wet);
}

// Cette fonction inonde la carte
// en propageant l'eau depuis les cases déjà inondées ('P' ou 'W').
// Elle utilise spread_water_from_tile pour propager l'eau.
// Elle retourne le nombre total de cases qui ont été transformées en eau.
static int	flood_map(char **map)
{
	int		i;
	int		j;
	int		been_wet;

	i = 0;
	been_wet = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'W')
				been_wet += spread_water(map, i, j);
			j++;
		}
		i++;
	}
	return (been_wet);
}

static int	flooded_map(char **map)
{
	return (count_elements(map, 'C') + count_elements(map, 'E'));
}

// Cette fonction vérifie si la carte est totalement inondée.
// Si certains collectibles ou la sortie ne sont pas inondés,
// elle affiche un message d'erreur.
void	parse_flood_map(char **map)
{
	char	**map_copy;
	int		has_spread;

	map_copy = dup_map(map);
	has_spread = 1;
	while (has_spread)
		has_spread = flood_map(map_copy);
	if (flooded_map(map_copy) != 0)
	{
		free_tab(map_copy);
		free_tab(map);
		handle_error("Collectibles or exit are not reachable.");
	}
	free_tab(map_copy);
}
