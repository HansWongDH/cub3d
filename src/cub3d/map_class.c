/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:11:49 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/15 15:57:39 by nfernand         ###   ########.fr       */
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

void	draw_square(int *img_data, t_coord tile_coord, int width, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			img_data[width * (i + tile_coord.x * TILE_SIZE)
				+ (j + tile_coord.y * TILE_SIZE)] = colour;
			j++;
		}
		i++;
	}
}

void	draw_tiles(t_map *map)
{
	t_coord	tile_coord;

	tile_coord.x = 0;
	while (tile_coord.x < map->row)
	{
		tile_coord.y = 0;
		while (tile_coord.y < map->col)
		{
			if (map->array[tile_coord.x][tile_coord.y] == '1')
				draw_square(map->img.data, tile_coord, map->width, GREEN);
			else if (map->array[tile_coord.x][tile_coord.y] == '0')
				draw_square(map->img.data, tile_coord, map->width, WHITE);
			else
				draw_square(map->img.data, tile_coord, map->width, BLACK);
			tile_coord.y++;
		}
		tile_coord.x++;
	}
}

void	draw_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < player->size)
	{
		j = 0;
		while (j < player->size)
		{
			map->img.data[map->width
				* ((int)player->pos.y + j - (player->size / 2))
				+ ((int)player->pos.x + i - (player->size / 2))] = PINK;
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *self, t_player *player)
{
	draw_tiles(self);
	draw_player(self, player);
}

t_map	map_init(void *mlx, char *file, t_coord *player_pos, int *player_direction)
{
	t_map	map;

	map.flag = 1;
	map.print_map = print_map;
	map.draw_map = draw_map;
	if (!map_parsing(&map, file, player_pos, player_direction))
	{
		map.flag = 0;
		return (map); //change later
	}
	map_create(&map, file, player_pos);
	if (!map_validation(&map))
	{
		ft_putstr_fd("Map Is Not Enclosed\n", 2);
		map.flag = 0;
		return (map); //change later
	}
	map.width = map.col* TILE_SIZE;
	map.height = map.row * TILE_SIZE;
	map.print_map(&map);
	map.img.img_p = mlx_new_image(mlx, map.width, map.height);
	map.img.data = (int *)mlx_get_data_addr(map.img.img_p,
			&map.img.bpp, &map.img.line_size, &map.img.endian);
	return (map);
}

//HAVE TO FREE MAP ARRAY LATER ON WHEN DESTRUCTOR IS CALLED

//int			draw_loop(t_data *data)
//{
//	(void)data;
//	data->test_map.draw_map(&data->test_map, &data->test_player);
//	mlx_put_image_to_window(data->mlx, data->win, data->test_map.img.pointer, 0, 0);
//	return (0);
//}
//
//int	main()
//{
//	t_data		data;
//
//	data.mlx = mlx_init();
//	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3d");
//	data.test_player = player_init();
//	data.test_map = map_init(ROW, COL, data.mlx);
//
//	mlx_loop_hook(data.mlx, draw_loop, &data);
//	mlx_loop(data.mlx);
//}
