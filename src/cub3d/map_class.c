/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:11:49 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/19 17:39:20 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

unsigned int	get_argb_val(int colour, int transparency)
{
	float	trasparency_percentage;
	int		col_in_argb;

	if (transparency < 0 || transparency > 100)
		return (colour);
	trasparency_percentage = (float)transparency / 100 * 255;
	col_in_argb = colour | ((int)trasparency_percentage << 24);
	return (col_in_argb);
}

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
				draw_square(map->img.data, tile_coord, map->width, get_argb_val(WALLCOL, MAP_TRANSPARENCY));
			else if (map->array[tile_coord.x][tile_coord.y] == '0')
				draw_square(map->img.data, tile_coord, map->width, get_argb_val(BLACK, MAP_TRANSPARENCY));
			else
				draw_square(map->img.data, tile_coord, map->width, get_argb_val(CIELCOL, MAP_TRANSPARENCY));
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
				+ ((int)player->pos.x + i - (player->size / 2))] = get_argb_val(RED, MAP_TRANSPARENCY - 20);
			j++;
		}
		i++;
	}
}

void	draw_player_direction(t_map *self, t_player *player)
{
	t_vec	ray;
	t_vec	delta;
	double	max;

	ray.x = player->pos.x;
	ray.y = player->pos.y;
	delta.x = cos(0) * player->ray_dir.x - sin(0) * player->ray_dir.y;
	delta.y = sin(0) * player->ray_dir.x + cos(0) * player->ray_dir.y;
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta.x /= max;
	delta.y /= max;
	while (1)
	{
		if (self->img.data[self->width * (int)floor(ray.y)
				+ (int)floor(ray.x)] != (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			self->img.data[self->width * (int)floor(ray.y)
				+ (int)floor(ray.x)] = BLUE;
		else
			break ;
		ray.x += delta.x;
		ray.y += delta.y;
	}
}

void	draw_display_player_direction(t_map *map, t_player *player)
{
	t_vec	ray;
	t_vec	delta;
	double	max;
	int		i;

	ray.x = map->display_width / 2;
	ray.y = map->display_height / 2;
	delta.x = cos(0) * player->ray_dir.x - sin(0) * player->ray_dir.y;
	delta.y = sin(0) * player->ray_dir.x + cos(0) * player->ray_dir.y;
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta.x /= max;
	delta.y /= max;
	i = 0;
	while (i < 15)
	{
		if (map->display.data[map->display_width * (int)floor(ray.y)
				+ (int)floor(ray.x)] != (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			map->display.data[map->display_width * (int)floor(ray.y)
				+ (int)floor(ray.x)] = get_argb_val(RED, MAP_TRANSPARENCY - 30);
		else
			break ;
		i++;
		ray.x += delta.x;
		ray.y += delta.y;
	}
}

void	draw_vision_line(t_map *self, t_player *player, double angle)
{
	t_vec	ray;
	t_vec	delta;
	double	max;
	float	distance;

	ray.x = player->pos.x;
	ray.y = player->pos.y;
	delta.x = cos(angle) * player->ray_dir.x - sin(angle) * player->ray_dir.y;
	delta.y = sin(angle) * player->ray_dir.x + cos(angle) * player->ray_dir.y;
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta.x /= max;
	delta.y /= max;
	distance = 0;
	while (1)
	{
		if (self->img.data[self->width * (int)floor(ray.y)
				+ (int)floor(ray.x)] != (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			self->img.data[self->width * (int)floor(ray.y)
				+ (int)floor(ray.x)] = GRAY;
		else
			break ;
		distance = sqrt(pow(player->pos.x - ray.x, 2) + pow(player->pos.y - ray.y, 2)) * cos(angle);
		ray.x += delta.x;
		ray.y += delta.y;
	}
}

void	draw_player_fov(t_map *self, t_player *player)
{
	double	angle;

	angle = 0;
	//while (angle < 2 * M_PI)
	while (angle < 45 * M_PI / 180)
	{
		draw_vision_line(self, player, angle);
		draw_vision_line(self, player, -angle);
		angle += (0.1 * M_PI / 180);
	}
}

//void	draw_square(int *img_data, t_coord tile_coord, int width, int colour)

void	draw_display_border(t_map *map)
{
	t_coord	coord;

	coord.x = 0;
	while (coord.x < 10)
	{
		coord.y = 0;
		while (coord.y < 10)
		{
			if ((coord.x == 0 || coord.x == DISPLAY_ROW - 1)
				|| (coord.y == 0 || coord.y == DISPLAY_COL - 1))
				draw_square(map->display.data, coord, map->display_width, get_argb_val(BLACK, MAP_TRANSPARENCY));
			else
				draw_square(map->display.data, coord, map->display_width, get_argb_val(CIELCOL, MAP_TRANSPARENCY));
			coord.y++;
		}
		coord.x++;
	}
}

void	draw_display_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < player->size)
	{
		j = 0;
		while (j < player->size)
		{
			map->display.data[map->display_width
				* (map->display_width / 2 + j - (player->size / 2))
				+ (map->display_height / 2 + i - (player->size / 2))] = get_argb_val(RED, MAP_TRANSPARENCY - 20);
			j++;
		}
		i++;
	}
}

//if (map->array[tile_coord.x][tile_coord.y] == '1')
//	draw_square(map->img.data, tile_coord, map->width, get_argb_val(WALLCOL, MAP_TRANSPARENCY));
//else if (map->array[tile_coord.x][tile_coord.y] == '0')
//	draw_square(map->img.data, tile_coord, map->width, get_argb_val(BLACK, MAP_TRANSPARENCY));
//else
//	draw_square(map->img.data, tile_coord, map->width, get_argb_val(CIELCOL, MAP_TRANSPARENCY));
//tile_coord.y++;

void	draw_display_map(t_map *map, t_player *player)
{
	t_coord	coord;
	t_coord	loop;

	(void)map;
	coord.x = (player->pos.x / TILE_SIZE) - 2;
	coord.y = (player->pos.y / TILE_SIZE) - 2; //remove ltr
	printf("player init coord       | %d %d\n", (int)(player->pos.x / TILE_SIZE), (int)(player->pos.y / TILE_SIZE));
	printf("player top left coord   | %d %d\n", coord.x, coord.y);
	loop.y = 1;
	while (loop.y < DISPLAY_ROW - 1)
	{
		loop.x = 1;
		coord.x = (player->pos.x / TILE_SIZE) - 2;
		while (loop.x < DISPLAY_COL - 1)
		{
			printf("========================\n");
			printf("place to draw    | %d %d\n", loop.x, loop.y);
			printf("tile to check    | %d %d\n", coord.x, coord.y);
			if ((coord.x >= 0 && coord.x < map->row)
				&& (coord.y >= 0 && coord.y < map->col))
			{
				printf("tile             |[%c]\n", map->array[coord.x][coord.y]);
				if (map->array[coord.x][coord.y] == '1')
				{
					printf("wall drawn       | %d %d\n", loop.x, loop.y);
					draw_square(map->display.data, loop, map->display_width, RED);
				}
			}
			printf("========================\n");
			coord.x++;
			loop.x++;
		}
		coord.y++;
		loop.y++;
	}
	exit(0);
}

void	draw_map(t_map *self, t_player *player)
{
	printf("row = %d\n", self->row);
	printf("col = %d\n", self->col);
	//for (int i = 0; i < self->row; i++)
	//{
	//	for (int j = 0; j < self->col; j++)
	//		printf("%c", self->array[i][j]);
	//		printf("\n");
	//}
	//for (int i = 0; self->array[i]; i++)
	//{
	//	for (int j = 0; self->array[i][j]; j++)
	//	{
	//		printf("j = %d\n", j);
	//	}
	//	printf("i = %d\n", i);
	//}
	draw_tiles(self);
	draw_player(self, player);
	// draw_player_fov(self, player);
	draw_display_border(self);
	draw_display_player(self, player);
	draw_display_player_direction(self, player);
	draw_display_map(self, player);
}

t_map	map_init(void *mlx, char *file, t_coord *player_pos, int *player_direction)
{
	t_map	map;

	map.flag = 1;
	map.print_map = print_map;
	map.draw_map = draw_map;
	map.draw_player_direction = draw_player_direction;
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
	map.width = map.col * TILE_SIZE;
	map.height = map.row * TILE_SIZE;
	map.print_map(&map);

	map.img.img_p = mlx_new_image(mlx, map.width, map.height);
	map.img.data = (int *)mlx_get_data_addr(map.img.img_p,
			&map.img.bpp, &map.img.line_size, &map.img.endian);

	map.display_width = DISPLAY_COL * TILE_SIZE;
	map.display_height = DISPLAY_ROW * TILE_SIZE;

	map.display.img_p = mlx_new_image(mlx, map.display_width, map.display_height);
	map.display.data = (int *)mlx_get_data_addr(map.display.img_p,
			&map.display.bpp, &map.display.line_size, &map.display.endian);
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
