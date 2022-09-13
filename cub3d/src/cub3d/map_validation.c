/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:08:17 by wding-ha          #+#    #+#             */
/*   Updated: 2022/09/02 17:40:17 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	map_edgechecking(t_map *map)
{
	int		i;
	char	*top;
	char	*btm;

	top = map->array[0];
	btm = map->array[map->row - 1];
	i = 0;
	while (top[i])
	{
		if (!ft_strchr("1 ", top[i]))
			return (0);
		i++;
	}
	i = 0;
	while (btm[i])
	{
		if (!ft_strchr("1 ", btm[i]))
			return (0);
		i++;
	}
	return (1);
}

int	map_spacechecking(t_map *map, int x, int y)
{
	if (y > 0)
	{
		if (map->array[y - 1][x] != ' ' && map->array[y - 1][x] != '1')
			return (0);
	}
	if (y < map->row - 1)
	{
		if (map->array[y + 1][x] != ' ' && map->array[y + 1][x] != '1')
			return (0);
	}
	if (x > 0)
	{
		if (map->array[y][x - 1] != ' ' && map->array[y][x - 1] != '1')
			return (0);
	}
	if (x < map->col - 1)
	{
		if (map->array[y][x + 1] != ' ' && map->array[y][x + 1] != '1')
			return (0);
	}
	return (1);
}

int	map_validation(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	(void)x;
	if (!map_edgechecking(map))
		return (set_map_flag(map, MAP_NOT_ENCLOSED));
	while (map->array[y])
	{
		x = 0;
		while (map->array[y][x])
		{
			if (map->array[y][x] == ' ')
			{
				if (!map_spacechecking(map, x, y))
					return (set_map_flag(map, MAP_NOT_ENCLOSED));
			}
			x++;
		}
		y++;
	}
	return (1);
}
