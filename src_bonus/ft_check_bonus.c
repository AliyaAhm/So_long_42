/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:43:26 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 10:28:48 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_wall_g(char *wall)
{
	size_t	count;

	count = 0;
	while (wall[count] == '1')
		count++;
	return (ft_strlen(wall) == count);
}

int	ft_check_wall_v(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		if (map->arr[i][0] != '1' || map->arr[i][map->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_simb(t_map *map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = "01CEPX";
	while (i < map->map_height)
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (!ft_strchr(str, map->arr[i][j]))
				ft_error("Map is invalid. !CPE10X");
			j++;
		}
		i++;
	}
	return ;
}

int	ft_count(char **arr, int ch, int h)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (!**arr || !ch)
		return (0);
	while (i < h)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == ch)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_check_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_height < 3)
		ft_error("Map is invalid. Height<3");
	while (i < map->map_height)
	{
		if ((int)ft_strlen(map->arr[i]) != map->map_width)
			ft_error("Map is invalid. Different size line");
		i++;
	}
	if (!ft_check_wall_g(map->arr[0])
		|| !ft_check_wall_g(map->arr[map->map_height - 1]))
		ft_error("Map is invalid. Gorizontall wall is empty");
	if (!ft_check_wall_v(map))
		ft_error("Map is invalid. Vertical wall is empty");
	ft_check_simb(map);
	map->coin = ft_count(map->arr, 'C', map->map_height);
	if (ft_count(map->arr, 'P', map->map_height) != 1
		|| ft_count(map->arr, 'E', map->map_height) != 1 || map->coin == 0)
		ft_error("Map is invalid. P !=1 E!=1 C =0");
}
