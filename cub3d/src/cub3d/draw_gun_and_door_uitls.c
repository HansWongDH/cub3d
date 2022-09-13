/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun_and_door_uitls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:27:12 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/29 18:31:36 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	toggle_door(char **array, int x, int y)
{
	if (array[y][x] == 'D')
		array[y][x] = 'd';
	else if (array[y][x] == 'd')
		array[y][x] = 'D';
}

void	put_gun_and_hud_image(t_data *data)
{
	int	x_offset_gun;

	x_offset_gun = 50;
	mlx_put_image_to_window(data->mlx, data->win,
		data->game.gun.img_p,
		WINDOW_WIDTH / 2 - (GUN_WIDTH * GUN_X_SCALE) / 2 - x_offset_gun,
		WINDOW_HEIGHT - (GUN_HEIGHT * GUN_Y_SCALE));
	mlx_put_image_to_window(data->mlx, data->win,
		data->game.background.img_p,
		0,
		WINDOW_HEIGHT - XPM_SIZE * HUD_Y_SCALE);
}
