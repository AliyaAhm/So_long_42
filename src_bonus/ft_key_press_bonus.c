/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:45:21 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 11:06:46 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_end_game(void)
{
	ft_printf("end_game");
	exit(0);
	return (0);
}

int	ft_game_over(void)
{
	ft_printf("game_over");
	exit(0);
	return (0);
}

void	ft_move1(t_game_map *game, int y_1, int x_1)
{
	game->map.arr[game->map.y + y_1][game->map.x + x_1] = 'P';
	game->map.arr[game->map.y][game->map.x] = '0';
	game->map.y += y_1;
	game->map.x += x_1;
	game->player.y = game->map.y;
	game->player.x = game->map.x;
	game->map.steps++;
}

void	ft_move(t_game_map *game, int y_1, int x_1)
{
	game->map.x = game->player.x;
	game->map.y = game->player.y;
	if (game->map.arr[game->map.y + y_1][game->map.x + x_1] == '0')
	{
		ft_move1(game, y_1, x_1);
	}
	else if (game->map.arr[game->map.y + y_1][game->map.x + x_1] == 'C')
	{
		ft_move1(game, y_1, x_1);
		game->map.coin--;
	}
	else if (game->map.arr[game->map.y + y_1][game->map.x + x_1] == 'E'
		&& game->map.coin == 0)
	{
		mlx_string_put(game->mlx, game->win, 20, 20, 0x00FF0000, "END_GAME");
		ft_end_game();
	}
	else if (game->map.arr[game->map.y + y_1][game->map.x + x_1] == 'X')
	{
		mlx_string_put(game->mlx, game->win, 20, 20, 0x00FF0000, "GAME_OVER");
		ft_game_over();
	}
}

int	ft_key_press(int key, t_game_map *game)
{
	if (key == UP || key == UP_B)
		ft_move(game, -1, 0);
	if (key == DOWN || key == DOWN_B)
		ft_move(game, 1, 0);
	if (key == LEFT || key == LEFT_B)
		ft_move(game, 0, -1);
	if (key == RIGHT || key == RIGHT_B)
		ft_move(game, 0, 1);
	else if (key == ESC)
		ft_end_game();
	return (0);
}
