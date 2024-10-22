/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:17:17 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/26 13:08:12 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img_interval(t_game *game, int interval)
{
	mlx_do_sync(game->mlx);
	usleep(interval);
}

t_coord	find_element_coord(char **map, char element)
{
	t_coord	coord;
	int		i;
	int		j;

	i = 0;
	coord.x = -1;
	coord.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
			{
				coord.x = j;
				coord.y = i;
				return (coord);
			}
			j++;
		}
		i++;
	}
	return (coord);
}

// void	print_map(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->height)
// 	{
// 		ft_printf("%s\n", map->map[i]);
// 		i++;
// 	}
// }

// Sauvegarder les paramètres du terminal actuels
// Mettre en place un nouveau terminal non bloquant
// Vérifier s'il y a une touche pressée
// Restaurer les paramètres du terminal
// Si une touche a été pressée, la remettre dans le flux d'entrée
int	kbhit(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return (1);
	}
	return (0);
}

// void print_image_info(t_img *img, const char *name)
// {
// 	ft_printf("Image %s: width=%d, height=%d, 
//	bpp=%d, line_length=%d, endian=%d\n",
//	name, img->width, img->height, img->bits_per_pixel,
//	img->line_length, img->endian);
// }