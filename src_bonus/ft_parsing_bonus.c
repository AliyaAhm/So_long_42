/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:45:29 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 09:50:43 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_name(char *name)
{
	char	*tmp;

	tmp = &name[ft_strlen(name) - 4];
	if (ft_strncmp(tmp, ".ber", 4) != 0)
		return (1);
	if (ft_strrchr(name, '/') && ft_strlen(ft_strrchr(name, '/')) == 5)
		return (1);
	return (0);
}

char	*ft_reading(char *name, t_map *map)
{
	int		fd;
	char	*line;
	char	*new_line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error("the map cannot be opened");
	map->map_height = 0;
	line = NULL;
	new_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		map->map_height++;
		new_line = ft_strjoin_gnl(new_line, line);
		free(line);
	}
	close(fd);
	return (new_line);
}

void	ft_parsing(int argc, char **argv, t_game_map *game)
{
	char	*line;

	if (argc != 2 || ft_check_name(argv[1]) || !game)
		ft_error("arguments is invalid01");
	line = ft_reading(argv[1], &game->map);
	game->map.arr = ft_split(line, '\n');
	if (!game->map.arr)
		ft_error("error arr");
	game->map.map_width = ft_strlen(game->map.arr[0]);
	game->map.steps = 0;
	free(line);
	return ;
}
