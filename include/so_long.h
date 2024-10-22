/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:20:44 by andjenna          #+#    #+#             */
/*   Updated: 2024/02/22 15:45:07 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_UP 119	  // 65362
# define KEY_DOWN 115  // 65364
# define KEY_LEFT 97	  // 65361
# define KEY_RIGHT 100 // 65363
# define KEY_ESC 65307
# define WIDTH 40
# define HEIGHT 20
# define NB_LIFE 3

typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_player
{
	int				health;
	int				step;
	t_coord			coord;
	t_img			*img_player[27];
}					t_player;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_exit
{
	t_coord			coord;
	t_img			*img_exit[10];
}					t_exit;

typedef struct s_coin
{
	int				nb_coin;
	t_coord			coord;
	t_img			*img_coin[4];
}					t_coin;

typedef struct s_wall
{
	t_img			*img_wall[14];
}					t_wall;

typedef struct s_monster
{
	int				nb_monster;
	t_coord			coord;
	t_img			*img_monster[8];
}					t_monster;

typedef struct s_way
{
	int				up;
	int				down;
	int				left;
	int				right;
}					t_way;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	time_t			last_keypress;
	t_coord			coord;
	t_map			*map;
	t_wall			*wall;
	t_coin			*coin;
	t_player		*player;
	t_monster		*monster;
	t_exit			*exit;
	t_way			*way;
}					t_game;

/*								PARSING ARG							*/
void				parse_arg(int ac, char **av);
void				map_is_rectangular(char *map_file);
void				map_is_surrounded_by_walls(char *map_file);
void				map_has_valid_chars(char *map_file);
void				parse_flood_map(char **map);

/*						   		  UTILS								*/
int					count_elements(char **map, char c);
int					map_len_x(char **map);
int					map_len_y(char **map);
size_t				map_len(char *map_file);
char				**read_map_from_file(int fd, char *map_file);
char				*supp_line_break(char *line);
char				**dup_map(char **map);
t_coord				find_element_coord(char **map, char element);
int					count_image_in_folder(char *folder);
void				print_image_info(t_img *img, const char *name);
void				print_map(t_map *map);
int					kbhit(void);
int					is_idle(t_game *game, int sec);
void				put_img_monster(t_game *game, int x, int y, int i);
void				put_img_player(t_game *game, int x, int y, int i);
void				put_img_exit(t_game *game, int x, int y, int i);
void				put_img_wall(t_game *game, int x, int y, int i);

/*								 ERRORS								*/
void				handle_error(char *str);
void				handle_error_gnl(char *line, int fd, char *str);
void				free_tab(char **tab);
void				destroy_img(t_game *game);
void				free_wall(t_game *game);
void				free_exit(t_game *game);
void				free_coin(t_game *game);
void				free_player(t_game *game);
void				free_monster(t_game *game);
void				handle_free(t_game *game);

/*								INIT GAME							*/
t_game				*init_game(t_game **game, char *map_file);
t_img				*init_img(t_game *game, char *path_image);
t_map				*init_map(char *map_file);
t_wall				*init_wall(t_game *game);
t_exit				*init_exit(t_game *game);
t_coin				*init_coin(t_game *game);
t_player			*init_player(t_game *game);
t_monster			*init_monster(t_game *game);
void				init_img_wall(t_game *game);
void				init_img_exit(t_game *game);
void				init_img_player(t_game *game);
void				init_img_coin(t_game *game);
void				init_img_monster(t_game *game);
void				init_img_game(t_game *game);
void				display_game(t_game *game);
void				display_exit(t_game *game);
void				display_collectible(t_game *game);
void				display_player(t_game *game);
void				display_monster(t_game *game);
void				display_wall_floor(t_game *game);
void				display_health(t_game *game);
void				display_so_long(t_game *game);
int					exit_game(t_game *game);
void				open_the_gate(t_game *game);
void				print_moove(t_game *game);

/*								ANIMATION							*/
int					animation_collectible(t_game *game);
int					animation_monster(t_game *game);
int					check_idle_and_start_animation(t_game *game,
						int flag, int x, int y);
void				img_interval(t_game *game, int interval);
void				player_get_hit(t_game *game);

/*								MOOVE								*/
void				set_moove(t_game *game);
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);
void				p_on_e(t_game *game);

#endif