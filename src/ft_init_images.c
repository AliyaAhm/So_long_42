/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:46:06 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 09:25:59 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_images(t_game_map	*game)
{
	int	x;
	int	y;

	x = SIZE_SPRITE;
	y = SIZE_SPRITE;
	game->map.wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &x, &y);
	game->map.player0 = mlx_xpm_file_to_image(game->mlx, PLAYER0, &x, &y);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->map.cell = mlx_xpm_file_to_image(game->mlx, CELL, &x, &y);
	if (!game->map.wall || !game->map.floor || !game->map.player0
		|| !game->map.exit || !game->map.cell)
	{
		ft_error("Don't open image");
	}
}
