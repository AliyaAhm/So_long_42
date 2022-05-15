/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:43:51 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 10:11:28 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_images(t_game_map *game)
{
	int	x;
	int	y;

	x = SIZE_SPRITE;
	y = SIZE_SPRITE;
	game->map.wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &x, &y);
	game->map.player0 = mlx_xpm_file_to_image(game->mlx, PLAYER0, &x, &y);
	game->map.player1 = mlx_xpm_file_to_image(game->mlx, PLAYER1, &x, &y);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->map.cell = mlx_xpm_file_to_image(game->mlx, CELL, &x, &y);
	game->map.enemy1 = mlx_xpm_file_to_image(game->mlx, ENEMY1, &x, &y);
	game->map.enemy2 = mlx_xpm_file_to_image(game->mlx, ENEMY2, &x, &y);
	if (!game->map.wall || !game->map.floor || !game->map.player0
		|| !game->map.exit || !game->map.cell || !game->map.enemy1
		|| !game->map.enemy2)
	{
		ft_error("Don't open image");
	}
	game->map.enemy = game->map.enemy1;
	ft_init_enemy(game);
}

void	ft_init_enemy(t_game_map *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (game->map.arr[j])
	{
		i = 0;
		while (game->map.arr[j][i])
		{
			if (game->map.arr[j][i] == 'X')
			{
				game->enemy_coord[count].x = i;
				game->enemy_coord[count].y = j;
				count++;
			}
			i++;
		}
		j++;
	}
	game->enemy = count;
}

void	ft_move_kaktus(t_game_map *game, int y_1, int x_1)
{
	int	i;

	i = 0;
	while (i < game->enemy)
	{
		if (game->map.arr[game->enemy_coord[i].y + y_1]
			[game->enemy_coord[i].x + x_1] == '0')
		{
			game->map.arr[game->enemy_coord[i].y + y_1]
			[game->enemy_coord[i].x + x_1] = 'X';
			game->map.arr[game->enemy_coord[i].y]
			[game->enemy_coord[i].x] = '0';
			game->enemy_coord[i].y += y_1;
			game->enemy_coord[i].x += x_1;
		}
		if (game->map.arr[game->enemy_coord[i].y + y_1]
			[game->enemy_coord[i].x + x_1] == 'P')
		{
			mlx_string_put(game->mlx, game->win, 20, 20,
				0x00FF0000, "GAME_OVER");
			ft_game_over();
		}
		i++;
	}
}

void	ft_enemy_move(t_game_map *game)
{
	int	i;

	i = rand() % 4;
	if (i == 0)
		ft_move_kaktus(game, -1, 0);
	if (i == 1)
		ft_move_kaktus(game, 1, 0);
	if (i == 2)
		ft_move_kaktus(game, 0, -1);
	if (i == 3)
		ft_move_kaktus(game, 0, 1);
	if (game->map.enemy == game->map.enemy1)
		game->map.enemy = game->map.enemy2;
	else if (game->map.enemy == game->map.enemy2)
		game->map.enemy = game->map.enemy1;
}
