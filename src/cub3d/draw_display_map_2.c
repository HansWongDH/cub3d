/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_display_map_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:30:20 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/30 11:48:55 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_display_player_direction(t_map *map, t_player *player)
{
	t_vec	ray;
	t_vec	delta;
	double	max;
	int		i;

	ray = equate_vectors_double(map->display_width / 2,
			map->display_height / 2);
	delta = equate_vectors_double(
			cos(0) * player->ray_dir.x - sin(0) * player->ray_dir.y,
			sin(0) * player->ray_dir.x + cos(0) * player->ray_dir.y);
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta = divide_vectors_double(delta, max, max);
	i = 0;
	while (i < player->size * 2)
	{
		if (map->display.data[map->display_width * (int)floor(ray.y)
				+ (int)floor(ray.x)]
			!= (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			map->display.data[map->display_width * (int)floor(ray.y)
				+ (int)floor(ray.x)] = get_argb_val(RED, MAP_TRANSPARENCY - 30);
		else
			break ;
		i++;
		ray = add_vectors(ray, delta);
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
			if (map->array[tile_coord.x][tile_coord.y] == '1'
					|| map->array[tile_coord.x][tile_coord.y] == 'D')
				draw_square(map->img.data, tile_coord,
					map->width, get_argb_val(WALLCOL, MAP_TRANSPARENCY));
			else if (map->array[tile_coord.x][tile_coord.y] == '0')
				draw_square(map->img.data, tile_coord,
					map->width, get_argb_val(BLACK, MAP_TRANSPARENCY));
			else
				draw_square(map->img.data, tile_coord,
					map->width, get_argb_val(CIELCOL, MAP_TRANSPARENCY));
			tile_coord.y++;
		}
		tile_coord.x++;
	}
}
