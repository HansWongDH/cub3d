/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_display_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:18:07 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/30 11:43:00 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_display_border(t_map *map)
{
	t_coord	coord;

	coord.x = 0;
	while (coord.x < DISPLAY_ROW)
	{
		coord.y = 0;
		while (coord.y < DISPLAY_COL)
		{
			if ((coord.x == 0 || coord.x == DISPLAY_ROW - 1)
				|| (coord.y == 0 || coord.y == DISPLAY_COL - 1))
				draw_square(map->display.data, coord,
					map->display_width, get_argb_val(BLACK, MAP_TRANSPARENCY));
			else
				draw_square(map->display.data, coord, map->display_width,
					get_argb_val(CIELCOL, MAP_TRANSPARENCY));
			coord.y++;
		}
		coord.x++;
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
				+ ((int)player->pos.x + i - (player->size / 2))]
				= get_argb_val(RED, MAP_TRANSPARENCY - 20);
			j++;
		}
		i++;
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
				+ (map->display_height / 2 + i - (player->size / 2))]
				= get_argb_val(RED, MAP_TRANSPARENCY - 20);
			j++;
		}
		i++;
	}
}

static void	draw_selected_object(t_map *map, t_coord coord, t_coord loop)
{
	if (map->array[coord.y][coord.x] == '1')
		draw_square(map->display.data, loop,
			map->display_width, get_argb_val(BLACK, MAP_TRANSPARENCY));
	else if (map->array[coord.y][coord.x] == 'D')
		draw_square(map->display.data, loop, map->display_width,
			get_argb_val(DOOR_OP_COL, MAP_TRANSPARENCY - 30));
	else if (map->array[coord.y][coord.x] == 'd')
		draw_square(map->display.data, loop, map->display_width,
			get_argb_val(DOOR_CL_COL, MAP_TRANSPARENCY - 30));
}

void	draw_display_map(t_map *map, t_player *player)
{
	t_coord	coord;
	t_coord	loop;

	loop.x = 1;
	coord.y = (int)(player->pos.y / TILE_SIZE) - (DISPLAY_COL / 2 - 1);
	while (loop.x < DISPLAY_COL - 1)
	{
		loop.y = 1;
		coord.x = (int)(player->pos.x / TILE_SIZE) - (DISPLAY_ROW / 2 - 1);
		while (loop.y < DISPLAY_ROW - 1)
		{
			if ((coord.x >= 0 && coord.x < map->col)
				&& (coord.y >= 0 && coord.y < map->row))
				draw_selected_object(map, coord, loop);
			else
				draw_square(map->display.data, loop,
					map->display_width, get_argb_val(BLACK, MAP_TRANSPARENCY));
			loop.y++;
			coord.x++;
		}
		loop.x++;
		coord.y++;
	}
}
