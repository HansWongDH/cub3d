/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:08:17 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/12 20:03:39 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		map_edgechecking(t_info *data)
{
	int		i;
	char	*top;
	char	*btm;

	top = data->map[0];
	btm = data->map[data->height - 1];
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
int		map_spacechecking(t_info *data, int	x, int y)
{
	if (y > 0)
	{
		if (data->map[y - 1][x] != ' ' && data->map[y - 1][x] != '1')
			return (0);
	}
	if (y < data->height - 1)
	{
		if (data->map[y + 1][x] != ' ' && data->map[y + 1][x] != '1')
			return (0);
	}
	if (x > 0)
	{
		if (data->map[y][x - 1] != ' ' && data->map[y][x - 1] != '1')
			return (0);
	}
	if (x < data->width - 1)
	{
		if (data->map[y][x + 1] != ' ' && data->map[y][x + 1] != '1')
			return (0);
	}
	return (1);
}


int		map_validation(t_info *data)
{
	int	x;
	int	y;

	y = 0;
	if (!map_edgechecking(data))
		return (0);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
			{
				if (!map_spacechecking(data, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
