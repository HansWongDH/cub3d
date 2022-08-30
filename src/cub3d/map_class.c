/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:11:49 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/30 15:58:38 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	print_map(t_map *self)
{
	int	i;
	int	j;

	i = 0;
	while (i < self->row)
	{
		j = 0;
		while (j < self->col)
		{
			if (self->array[i][j] == '1')
				printf("1");
			else if (self->array[i][j] == '0')
				printf("0");
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_map(t_map *self, t_player *player)
{
	draw_tiles(self);
	draw_player(self, player);
	draw_display_border(self);
	draw_display_map(self, player);
	draw_display_player(self, player);
	draw_display_player_direction(self, player);
}

static void	init_wall_path(t_data *data)
{
	data->north_wall.path = NULL;
	data->east_wall.path = NULL;
	data->south_wall.path = NULL;
	data->west_wall.path = NULL;
}

static void	init_map_img(t_data *data, t_map *map)
{
	map->img.img_p = mlx_new_image(data->mlx, map->width, map->height);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_p,
			&map->img.bpp, &map->img.line_size, &map->img.endian);
	map->display_width = DISPLAY_COL * TILE_SIZE;
	map->display_height = DISPLAY_ROW * TILE_SIZE;
	map->display.img_p = mlx_new_image(data->mlx, map->display_width,
			map->display_height);
	map->display.data = (int *)mlx_get_data_addr(map->display.img_p,
			&map->display.bpp, &map->display.line_size, &map->display.endian);
}

t_map	map_init(t_data *data, char *file)
{
	t_map		map;

	map.flag = 1;
	map.player_direction = 0;
	map.print_map = print_map;
	map.draw_map = draw_map;
	init_wall_path(data);
	if (!map_parsing(&map, data, file))
	{
		map.flag = 0;
		return (map);
	}
	map_create(&map, file, data->index);
	if (!map_validation(&map))
	{
		ft_putstr_fd("Map Is Not Enclosed\n", 2);
		map.flag = 0;
		return (map);
	}
	map.width = map.col * TILE_SIZE;
	map.height = map.row * TILE_SIZE;
	init_map_img(data, &map);
	map.print_map(&map);
	return (map);
}

//HAVE TO FREE MAP ARRAY LATER ON WHEN DESTRUCTOR IS CALLED
//HAVE TO ALSO HANDLE PROPER MAP RETURN SHIT
