/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:18:57 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/29 17:20:24 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_gun(t_data *data, char *path_to_xpm)
{
	t_xpm	texture;
	t_coord	loop;

	init_xpm(data->mlx, &texture, path_to_xpm);
	loop.x = 0;
	while (loop.x < GUN_HEIGHT * GUN_X_SCALE)
	{
		loop.y = 0;
		while (loop.y < GUN_WIDTH * GUN_Y_SCALE)
		{
			if (loop.y % GUN_Y_SCALE == 0)
				data->game.gun.data[GUN_WIDTH * GUN_X_SCALE * loop.y + loop.x]
					= texture.data[GUN_WIDTH * (loop.y / GUN_Y_SCALE)
					+ (loop.x / GUN_X_SCALE)];
			else
				data->game.gun.data[GUN_WIDTH * GUN_X_SCALE * loop.y + loop.x]
					= texture.data[GUN_WIDTH
					* ((loop.y - loop.y % GUN_Y_SCALE) / GUN_Y_SCALE)
					+ ((loop.x - loop.x % GUN_X_SCALE) / GUN_X_SCALE)];
			loop.y++;
		}
		loop.x++;
	}
}
