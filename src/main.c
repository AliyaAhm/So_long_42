/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:46:20 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 09:45:52 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	write(2, "ERROR: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game_map	*game;
	int			i;

	game = (t_game_map *)malloc(sizeof(t_game_map));
	if (!game)
		ft_error("memory allocation error");
	ft_parsing(argc, argv, game);
	ft_check_map(&game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.map_width * SIZE_SPRITE, \
							game->map.map_height * SIZE_SPRITE, "so_long");
	ft_init_images(game);
	mlx_hook(game->win, 2, 0, ft_key_press, game);
	mlx_hook(game->win, 17, 0, ft_end_game, &game->map);
	mlx_loop_hook(game->mlx, ft_draw_map, game);
	mlx_loop(game->mlx);
	i = -1;
	while (game->map.arr[++i])
		free(game->map.arr[i]);
	free(game->map.arr);
	free(game);
	exit(0);
}
