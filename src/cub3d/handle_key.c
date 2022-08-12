/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:45:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/12 15:50:30 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player.move_player(&data->player, data->map.img.data, KEY_W);
	if (keycode == KEY_A)
		data->player.turn_player(&data->player, KEY_A);
	if (keycode == KEY_S)
		data->player.move_player(&data->player, data->map.img.data, KEY_S);
	if (keycode == KEY_D)
		data->player.turn_player(&data->player, KEY_D);
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		data->player.print_player(&data->player);
	return (0);
}

int	handle_exit(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
}
