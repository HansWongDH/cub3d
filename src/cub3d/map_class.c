/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:11:49 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/12 13:58:57 by nfernand         ###   ########.fr       */
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
			if (self->array[i][j] == 1)
				printf("1 ");
			else
				printf("0 ");
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
			if (map->array[tile_coord.x][tile_coord.y] == 1)
				draw_square(map->img.data, tile_coord, map->width, GREEN);
			if (map->array[tile_coord.x][tile_coord.y] == 0)
				draw_square(map->img.data, tile_coord, map->width, WHITE);
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
				* ((int)player->pos.x + j - (player->size / 2))
				+ ((int)player->pos.y + i - (player->size / 2))] = PINK;
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

t_map	map_init(int row, int col, void	*mlx)
{
	t_map	map;
	int  array[ROW][COL] =  {
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  1 ,	1 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	0 ,  0 ,  0 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 }
	};

	map.print_map = print_map;
	map.draw_map = draw_map;
	map.row = row;
	map.col = col;
	map.width = col * TILE_SIZE;
	map.height = row * TILE_SIZE;
	ft_memcpy(map.array, array, sizeof(int) * row * col);
	map.img.img_p = mlx_new_image(mlx, map.width, map.height);
	map.img.data = (int *)mlx_get_data_addr(map.img.img_p,
			&map.img.bpp, &map.img.line_size, &map.img.endian);
	return (map);
}

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
