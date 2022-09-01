/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:45:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 09:49:00 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S)
		data->player.move_player(&data->player, keycode, &data->map);
	if (keycode == KEY_A || keycode == KEY_D)
		data->player.turn_player(&data->player, keycode);
	if (is_movement_keys(keycode) == 2)
		data->player.turn_player(&data->player, keycode);
	if (keycode == KEY_SPACE)
		data->game.shoot_gun(data);
	if (keycode == KEY_ESC)
	{
		freestr(data->map.array);
		exit(0);
	}
	if (is_movement_keys(keycode) >= 1)
		data->player.print_player(&data->player);
	if (keycode == KEY_E)
		data->game.open_door(data);
	return (0);
}

//free or someshit here

int	handle_exit(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	static int	reset = 0;

	(void)y;
	if (x < 0 || x > WINDOW_WIDTH)
	{
		mlx_mouse_move(data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		reset = 1;
	}
	else if (reset == 0)
		data->player.turn_player_mouse(&data->player,
			(double)(data->mouse_pos.x - x) / WINDOW_WIDTH * -1);
	else if (reset == 1)
		reset = 0;
	data->mouse_pos.x = x;
	return (0);
}
