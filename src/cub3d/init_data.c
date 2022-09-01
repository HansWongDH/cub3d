/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:00:08 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 11:09:50 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static void	init_textures_2(t_data *data)
{
	data->east_wall.img_p = mlx_xpm_file_to_image(data->mlx,
			data->east_wall.path, &data->east_wall.width,
			&data->east_wall.height);
	data->east_wall.data = (int *)mlx_get_data_addr(data->east_wall.img_p,
			&data->east_wall.bpp, &data->east_wall.line_size,
			&data->east_wall.endian);
	data->door.img_p = mlx_xpm_file_to_image(data->mlx,
			"./textures/DOOR_3B.xpm", &data->door.width,
			&data->door.height);
	data->door.data = (int *)mlx_get_data_addr(data->door.img_p,
			&data->door.bpp, &data->door.line_size, &data->door.endian);
}

static void	init_textures(t_data *data)
{
	data->north_wall.img_p = mlx_xpm_file_to_image(data->mlx,
			data->north_wall.path, &data->north_wall.width,
			&data->north_wall.height);
	data->north_wall.data = (int *)mlx_get_data_addr(data->north_wall.img_p,
			&data->north_wall.bpp, &data->north_wall.line_size,
			&data->north_wall.endian);
	data->west_wall.img_p = mlx_xpm_file_to_image(data->mlx,
			data->west_wall.path, &data->west_wall.width,
			&data->west_wall.height);
	data->west_wall.data = (int *)mlx_get_data_addr(data->west_wall.img_p,
			&data->west_wall.bpp, &data->west_wall.line_size,
			&data->west_wall.endian);
	data->south_wall.img_p = mlx_xpm_file_to_image(data->mlx,
			data->south_wall.path, &data->south_wall.width,
			&data->south_wall.height);
	data->south_wall.data = (int *)mlx_get_data_addr(data->south_wall.img_p,
			&data->south_wall.bpp, &data->south_wall.line_size,
			&data->south_wall.endian);
}

//free all data

void	init_data(t_data *data, char *file)
{
	data->index = 0;
	data->floor = -1;
	data->ceiling = -1;
	data->mlx = mlx_init();
	data->map = map_init(data, file);
	if (data->map.flag != MAP_OK)
	{
		print_map_error(data->map.flag);
		printf("EXITED HERE\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->player = player_init(data->map.player_pos,
			data->map.player_direction);
	data->game = game_init(data->mlx);
	init_textures(data);
	init_textures_2(data);
}
