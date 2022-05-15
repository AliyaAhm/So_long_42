/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:43:42 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 11:08:05 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_map2(t_game_map *game, int i, int j)
{
	if (game->map.arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.wall, j * SIZE_SPRITE, i * SIZE_SPRITE);
	else if (game->map.arr[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.floor, j * SIZE_SPRITE, i * SIZE_SPRITE);
	else if (game->map.arr[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.player0, j * SIZE_SPRITE, i * SIZE_SPRITE);
		game->player.x = j;
		game->player.y = i;
	}
	else if (game->map.arr[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.exit, j * SIZE_SPRITE, i * SIZE_SPRITE);
	else if (game->map.arr[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.cell, j * SIZE_SPRITE, i * SIZE_SPRITE);
}

void	ft_draw_map3(t_game_map *game, int i, int j)
{
	if (game->map.arr[i][j] == 'X')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->map.enemy, j * SIZE_SPRITE, i * SIZE_SPRITE);
	}
}

void	ft_draw_map1(t_game_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.arr[i])
	{
		j = 0;
		while (game->map.arr[i][j])
		{
			ft_draw_map2(game, i, j);
			ft_draw_map3(game, i, j);
			j++;
		}
		i++;
	}
}

int	ft_draw_map(t_game_map *game)
{
	char		*count_step;
	static int	l;

	l++;
	if (l > 20)
	{
		ft_enemy_move(game);
		l = 0;
	}
	ft_draw_map1(game);
	count_step = ft_itoa(game->map.steps);
	mlx_string_put(game->mlx, game->win, 20, 20, 0x00FF0000, "Steps:");
	mlx_string_put(game->mlx, game->win, 85, 20, 0x00FF0000, count_step);
	free(count_step);
	return (0);
}
