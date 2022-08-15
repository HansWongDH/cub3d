/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:07:32 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/15 15:35:59 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	put_images(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->map.img.img_p, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->north_wall.img_p, XPM_SIZE, HEIGHT);
	mlx_put_image_to_window(data->mlx, data->win, data->east_wall.img_p, XPM_SIZE * 2, HEIGHT + XPM_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->south_wall.img_p, XPM_SIZE, HEIGHT + 2 * XPM_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->west_wall.img_p, 0, HEIGHT + XPM_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->game.img_p, WIDTH + 10, 0);
}

int			draw_loop(t_data *data)
{
	data->map.draw_map(&data->map, &data->player);
	mlx_put_image_to_window(data->mlx, data->win, data->map.img.img_p, 0, 0);
	put_images(data);
	return (0);
}

void	start_game(t_data *data)
{
	mlx_hook(data->win, X_KEY_PRESS, 0, handle_key, data);
	mlx_hook(data->win, X_KEY_EXIT, 0, handle_exit, data);
	mlx_loop_hook(data->mlx, draw_loop, data);
	mlx_loop(data->mlx);
}

int		main(int ac, char **av)
{
	t_data	data;

	init_data(&data, av[1], ac);
	start_game(&data);
}
