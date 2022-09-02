/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:30:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 13:49:45 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static void	render_walls(t_data *data, t_math *math, int index)
{
	int		j;
	int		game_pos_to_draw;
	int		max;
	t_xpm	img;

	j = 0;
	max = (TILE_SIZE * Y_SCALE) / (math->wall_distance);
	img = get_texture(data, math, math->side);
	while (j < max)
	{
		game_pos_to_draw = get_pos_to_draw(data, -1, j, index);
		if (game_pos_to_draw <= data->game.width * data->game.height)
		{
			data->game.img.data[game_pos_to_draw]
				= img.data[get_xpm_pos(&img, (double)j / max, math->wall, 0)];
		}
		game_pos_to_draw = get_pos_to_draw(data, max, j, index);
		if (data->game.width * data->game.height - game_pos_to_draw >= 0)
		{
			data->game.img.data[data->game.width
				* data->game.height - game_pos_to_draw]
				= img.data[get_xpm_pos(&img, (double)j / max, math->wall, 1)];
		}
		j++;
	}
}

static void	get_side_magtitude(t_math *math, t_player *player)
{
	if (math->ray_dir.x < 0)
	{
		math->step.x = -1;
		math->side_dist.x = (player->pos.x - math->map_pos.x)
			* math->delta_dist.x;
	}
	else
	{
		math->step.x = 1;
		math->side_dist.x = (math->map_pos.x + 1.0 - player->pos.x)
			* math->delta_dist.x;
	}
	if (math->ray_dir.y < 0)
	{
		math->step.y = -1;
		math->side_dist.y = (player->pos.y - math->map_pos.y)
			* math->delta_dist.y;
	}
	else
	{
		math->step.y = 1;
		math->side_dist.y = (math->map_pos.y + 1.0 - player->pos.y)
			* math->delta_dist.y;
	}
}

static double	execute_dda(t_math *math, t_map *map)
{
	double	dist;
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		math->side = check_side(math);
		flag_collision(math, map->array, &hit);
	}
	if (math->side == 0)
		dist = math->side_dist.x - math->delta_dist.x;
	else
		dist = math->side_dist.y - math->delta_dist.y;
	return (dist);
}

static double	wall_collision(t_math *math, t_data *data)
{
	double	wall;

	if (math->side == 0)
		wall = data->player.pos.y + math->wall_distance * math->ray_dir.y;
	else
		wall = data->player.pos.x + math->wall_distance * math->ray_dir.x;
	wall /= TILE_SIZE;
	return (wall - floor(wall));
}

void	draw_game_render(t_data *data)
{
	t_math	math;
	int		i;

	i = 1;
	while (i <= data->game.width)
	{
		math.door = 0;
		math.camera_x = 2 * i / (double)data->game.width - 1;
		math.ray_dir.x = data->player.ray_dir.x
			+ data->player.plane_dir.x * math.camera_x;
		math.ray_dir.y = data->player.ray_dir.y
			+ data->player.plane_dir.y * math.camera_x;
		math.delta_dist.x = fabs(1 / (math.ray_dir.x));
		math.delta_dist.y = fabs(1 / (math.ray_dir.y));
		math.map_pos.x = (int)data->player.pos.x;
		math.map_pos.y = (int)data->player.pos.y;
		get_side_magtitude(&math, &data->player);
		math.wall_distance = execute_dda(&math, &data->map);
		math.wall = wall_collision(&math, data);
		render_walls(data, &math, i);
		i++;
	}
}
