/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:46:32 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 10:44:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx/mlx.h"

# include <stdlib.h>
# include <stdio.h> // strerror()*/
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
/*# include <string.h> // strerror()*/

// keys
# define ESC	53 //ESC
# define UP		13 //W
# define DOWN	1 //S
# define LEFT	0 //A
# define RIGHT	2 //D

// keys bonus
# define UP_B		126 //W
# define DOWN_B	    125 //S
# define LEFT_B     123 //A
# define RIGHT_B	124 //D

// sprites
# define WALL		"image/1.xpm"
# define FLOOR		"image/0.xpm"
# define PLAYER0	"image/P1.xpm"
# define PLAYER1	"image/P0.xpm"
# define EXIT		"image/E.xpm"
# define CELL		"image/C.xpm"
# define ENEMY0		"image/X.xpm"
# define ENEMY1		"image/X1.xpm"
# define ENEMY2		"image/X2.xpm"

// size sprite X Y
# define SIZE_SPRITE	50

typedef struct s_map
{
	char	**arr;
	int		x;
	int		y;
	int		map_height;
	int		map_width;
	int		coin;
	void	*wall;
	void	*floor;
	void	*player0;
	void	*player1;
	void	*exit;
	void	*cell;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
	int		steps;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_game_map
{
	t_map		map;
	t_player	player;
	t_enemy		enemy_coord[20];
	void		*mlx;
	void		*win;
	int			size;
	int			enemy;
}	t_game_map;

/*ft_parsing.c*/
void	ft_parsing(int argc, char **argv, t_game_map *game);
char	*ft_reading(char *name, t_map *map);
int		ft_check_name(char *name);/*проверяем .ber*/

/*main.c*/
void	ft_error(char *str);

/*ft_check.c*/
int		ft_check_wall_g(char *wall); //проверяем горизонтальную линию на 1
int		ft_check_wall_v(t_map *map); //проверяем вертикальную линию на 1
void	ft_check_simb(t_map *map); //проверяем CPE01
int		ft_count(char **arr, int ch, int i);//счетчик
void	ft_check_map(t_map *map);//проверяем карту

/*ft_draw_map.c*/
int		ft_draw_map(t_game_map *game);
void	ft_draw_map1(t_game_map *game);
void	ft_draw_map2(t_game_map *game, int i, int j);
void	ft_draw_map3(t_game_map *game, int i, int j);

/*ft_init image.c*/
void	ft_init_images(t_game_map *game);
void	ft_init_enemy(t_game_map *game);
void	ft_enemy_move(t_game_map *game);
void	ft_move_kaktus(t_game_map *game, int y_1, int x_1);

/*ft_key_press.c*/
int		ft_key_press(int key, t_game_map *game);
void	ft_move(t_game_map *game, int y_1, int x_1);
int		ft_end_game(void);
int		ft_game_over(void);
void	ft_move1(t_game_map *game, int y_1, int x_1);

/*
Двумерный массив = одномерный
arr[y][x] = arr[y*width + x]
0   1   2   3   4   5
6   7   8   9   10  11
12  13  14  15  16  17
18  19  20  21  22  23
24  25  26  27  28  29
30  31  32  33  34  35*/

#endif