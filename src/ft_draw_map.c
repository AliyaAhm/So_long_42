/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:46:01 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 09:23:56 by oshelba          ###   ########.fr       */
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

int	ft_draw_map(t_game_map *game)
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
			j++;
		}
		i++;
	}
	return (0);
}
