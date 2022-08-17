/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:40:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/17 13:21:40 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_sky(t_game *self)
{
	int i;
	int j;

	i = 0;
	while (i < self->width)
	{
		j = 0;
		while (j < self->height)
		{
			if (j > self->height / 2)
				self->img.data[self->width * j + i] = FLOORCOL;
			else
				self->img.data[self->width * j + i] = CIELCOL;
			j++;
		}
		i++;
	}
}

//void	find_wall_collision(t_game *game, t_map *map, t_player *player, double angle)
//{
//	t_vec	ray;
//	t_vec	magnitude;
//	double	max;
//	int		pos;
//
//	ray.x = player->pos.x;
//	ray.y = player->pos.y;
//	magnitude.x = cos(angle) * player->ray_dir.x - sin(angle) * player->ray_dir.y;
//	magnitude.y = sin(angle) * player->ray_dir.x + cos(angle) * player->ray_dir.y;
//	max = fmax(fabs(magnitude.x), fabs(magnitude.y));
//	magnitude.x /= max;
//	magnitude.y /= max;
//	while (1)
//	{
//		pos = map->width * (int)floor(ray.y) + (int)floor(ray.x);
//		if (map->img.data[pos] != (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
//			map->img.data[pos] = RED;
//		else
//		{
//			render_walls(game, map, player);
//			break ;
//		}
//		ray.x += magnitude.x;
//		ray.y += magnitude.y;
//	}
//}

t_direction	get_direction_of_ray(double player_direction, double angle_offset)
{
	double	angle;

	angle = get_positive_value_of_angle(player_direction + angle_offset);
	if (angle > 5 * M_PI / 4 && angle <= 7 * M_PI / 4)
		return (NORTH);
	if ((angle > 7 * M_PI / 4 && angle <= 2 * M_PI)
			|| (angle >= 0 && angle <= M_PI / 4))
		return (EAST);
	if (angle > M_PI / 4 && angle <= 3 * M_PI / 4)
		return (SOUTH);
	return (WEST);
}

double		get_x_offset_for_tile_position(t_direction direction, t_vec vec)
{
	if (direction == NORTH || direction == SOUTH)
		return (fmodf(vec.x / TILE_SIZE, 1) * XPM_SIZE);
	return (fmodf(vec.y / TILE_SIZE, 1) * XPM_SIZE);
}

void	render_walls(t_data *data, t_vec ray, double angle)
{
	double		distance;
	double		x_offset;
	int			game_pos_to_draw;
	int			xpm_pos;
	t_direction	direction;
	t_coord		loop;

	distance = sqrt(pow(data->player.pos.x - ray.x, 2) + pow(data->player.pos.y - ray.y, 2)) * cos(angle);
	direction = get_direction_of_ray(data->player.direction, angle);
	x_offset = get_x_offset_for_tile_position(direction, ray);

	//printf("====================\n");
	//printf("player xy | %f,%f\n", data->player.pos.x, data->player.pos.y);
	//printf("distance  | %f\n", distance);
	//printf("x_scale   | %d\n", X_SCALE);
	//printf("y_scale   | %d\n", (int)Y_SCALE(distance));
	//printf("direction | %d\n", direction);
	//printf("x_offset  | %f\n", x_offset);
	//printf("width     | %d\n", data->game.width);
	//printf("height    | %d\n", data->game.height);
	//printf("====================\n");
	loop.x = 0;
	while (loop.x < X_SCALE)
	{
		loop.y = 0;
		while (loop.y < Y_SCALE(distance))
		{
			game_pos_to_draw = data->game.width * (loop.y + data->game.height/2 - (int)Y_SCALE(distance)/2)
				+ (loop.x + data->game.width/2 + - X_SCALE/2 + (int)(angle * 180 / M_PI * 20) - X_SCALE/2);
			xpm_pos = XPM_SIZE * (int)((float)loop.y/(float)Y_SCALE(distance) * XPM_SIZE) + (int)x_offset;
			data->game.img.data[game_pos_to_draw] = data->north_wall.data[xpm_pos];
			loop.y++;
		}
		loop.x++;
	}
}

void	find_wall_collision(t_data *data, double angle)
{
	t_vec	ray;
	t_vec	magnitude;
	double	max;
	int		pos;

	ray.x = data->player.pos.x;
	ray.y = data->player.pos.y;
	magnitude.x = cos(angle) * data->player.ray_dir.x - sin(angle) * data->player.ray_dir.y;
	magnitude.y = sin(angle) * data->player.ray_dir.x + cos(angle) * data->player.ray_dir.y;
	max = fmax(fabs(magnitude.x), fabs(magnitude.y));
	magnitude.x /= max;
	magnitude.y /= max;
	while (1)
	{
		pos = data->map.width * (int)floor(ray.y) + (int)floor(ray.x);
		if (data->map.img.data[pos] != (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			data->map.img.data[pos] = RED;
		else
		{
			render_walls(data, ray, angle);
			break ;
		}
		ray.x += magnitude.x;
		ray.y += magnitude.y;
	}
}

//void	draw_game(t_data *data)
void	draw_game(t_game *self, t_map *map, t_player *player, t_xpm *wall)
{
	double	angle;
	t_data	data;

	angle = 0;
	data.game = *self; //i have fucking circular dependency issues
	data.map = *map;
	data.player = *player;
	data.north_wall = *wall;
	//find_wall_collision(&data, 0);
	//find_wall_collision(&data, 1);
	//find_wall_collision(&data, -1);

	while (angle < (M_PI * 30/180))
	{
		//find_wall_collision(self, map, player, angle);
		//find_wall_collision(self, map, player, -angle);
		find_wall_collision(&data, angle);
		find_wall_collision(&data, -angle);
		angle += (M_PI * 0.1/180);
	}
}

t_game	game_init(t_map *map, void *mlx)
{
	t_game	game;

	//game.height = map->height * 3; //i have no idea why its 3
	//game.width = map->width * 3;
	(void)map;
	game.draw_game = draw_game;
	game.width = WINDOW_WIDTH;
	game.height = WINDOW_HEIGHT;
	game.draw_sky = draw_sky;
	game.img.img_p = mlx_new_image(mlx, game.width, game.height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img_p,
			&game.img.bpp, &game.img.line_size, &game.img.endian);
	return (game);
}
