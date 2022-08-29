/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:45:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/29 18:22:56 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	is_movement_keys(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		return (1);
	if (keycode == KEY_U_ARROW || keycode == KEY_R_ARROW || keycode == KEY_D_ARROW || keycode == KEY_L_ARROW)
		return (2);
	return (0);
}

int	handle_key(int keycode, t_data *data) //can change to looping over funtion pointers
{
	if (keycode == KEY_W)
		data->player.move_player(&data->player, KEY_W, &data->map);
	if (keycode == KEY_A)
		data->player.turn_player(&data->player, KEY_A);
	if (keycode == KEY_S)
		data->player.move_player(&data->player, KEY_S, &data->map);
	if (keycode == KEY_D)
		data->player.turn_player(&data->player, KEY_D);
	if (keycode == KEY_U_ARROW)
		data->player.turn_player(&data->player, KEY_U_ARROW);
	if (keycode == KEY_R_ARROW)
		data->player.turn_player(&data->player, KEY_R_ARROW);
	if (keycode == KEY_D_ARROW)
		data->player.turn_player(&data->player, KEY_D_ARROW);
	if (keycode == KEY_L_ARROW)
		data->player.turn_player(&data->player, KEY_L_ARROW);
	if (keycode == KEY_SPACE)
		data->game.shoot_gun(data);
	if (keycode == KEY_ESC)
		exit(0);
	if (is_movement_keys(keycode) >= 1)
		data->player.print_player(&data->player);
	if (keycode == KEY_E)
	{
		data->game.open_door(data);
		data->mouse_pos.x = GAME_WIDTH / 2;
	}
	return (0);
}

int	handle_exit(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	//idk what how the fuck im supposed to achive mouse
	//movement based on mouse displacemnt NOT relative to pixel pos
	//can ntry to reset mouse to middle everytime but all mouse prototyeps dont fucking work
	(void)y;
	if (data->mouse_pos.x == -1)
	{
		data->mouse_pos.x = x;
		return (0);
	}
	printf("================\n");
	printf("old = %d\n", data->mouse_pos.x);
	printf("new = %d\n", x);
	if (x >= 0 && x <= WINDOW_WIDTH)
	{
		if (abs(x - data->mouse_pos.x) > 10)
		{
			if (x > data->mouse_pos.x)
				data->player.turn_player(&data->player, KEY_D);
			else if (x < data->mouse_pos.x)
				data->player.turn_player(&data->player, KEY_A);
			else
				return (0);
			printf("================\n");
			data->mouse_pos.x = x;
		}
	}
	return (0);
}
