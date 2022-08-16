/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:00:08 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/16 13:50:14 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	init_xpm(t_data *data)
{
	data->north_wall.img_p = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_North.xpm", &data->north_wall.width, &data->north_wall.height);
	data->north_wall.data = (int*)mlx_get_data_addr(data->north_wall.img_p,
			&data->north_wall.bpp, &data->north_wall.line_size, &data->north_wall.endian);

	data->east_wall.img_p = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_East.xpm", &data->east_wall.width, &data->east_wall.height);
	data->east_wall.data = (int*)mlx_get_data_addr(data->east_wall.img_p,
			&data->east_wall.bpp, &data->east_wall.line_size, &data->east_wall.endian);

	data->south_wall.img_p = mlx_xpm_file_to_image(data->mlx, "./textures/SUPPORT_5B.xpm", &data->south_wall.width, &data->south_wall.height);
	data->south_wall.data = (int*)mlx_get_data_addr(data->south_wall.img_p,
			&data->south_wall.bpp, &data->south_wall.line_size, &data->south_wall.endian);

	data->west_wall.img_p = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_West.xpm", &data->west_wall.width, &data->west_wall.height);
	data->west_wall.data = (int*)mlx_get_data_addr(data->west_wall.img_p,
			&data->west_wall.bpp, &data->west_wall.line_size, &data->west_wall.endian);
}

void	init_images(t_data *data)
{
	data->map.img.img_p = mlx_new_image(data->mlx, data->map.width, data->map.height);
	data->map.img.data = (int*)mlx_get_data_addr(data->map.img.img_p,
			&data->map.img.bpp, &data->map.img.line_size, &data->map.img.endian);
	data->game.img.img_p = mlx_new_image(data->mlx, data->game.width, data->game.height);
	data->game.img.data = (int*)mlx_get_data_addr(data->game.img.img_p,
			&data->game.img.bpp, &data->game.img.line_size, &data->game.img.endian);
}

void	init_data(t_data *data, char *file)
{
	t_coord	player_pos;
	int		player_direction;

	player_direction = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->map = map_init(data->mlx, file, &player_pos, &player_direction);
	if (data->map.flag == 0)
	{
		//free all data
		exit(1);
	}
	data->player = player_init(player_pos, player_direction);
	data->game = game_init(&data->map, data->mlx);
	init_images(data);
	init_xpm(data);
}
