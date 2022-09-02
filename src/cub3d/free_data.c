/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:13:21 by wding-ha          #+#    #+#             */
/*   Updated: 2022/09/02 18:15:59 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *data)
{
	free_2d(data->map.array);
	free(data->north_wall.path);
	free(data->east_wall.path);
	free(data->south_wall.path);
	free(data->west_wall.path);
	mlx_destroy_image(data->mlx, data->game.gun.img_p);
	mlx_destroy_image(data->mlx, data->game.background.img_p);
	mlx_destroy_image(data->mlx, data->game.img.img_p);
	mlx_destroy_image(data->mlx, data->map.img.img_p);
	mlx_destroy_image(data->mlx, data->map.display.img_p);
	mlx_destroy_window(data->mlx, data->win);
}
