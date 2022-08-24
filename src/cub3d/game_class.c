/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:40:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/24 08:51:27 by nfernand         ###   ########.fr       */
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

void	open_door(t_data *data)
{
	int	direction;
	int	x;
	int	y;

	x = data->player.pos.x / TILE_SIZE;
	y = data->player.pos.y / TILE_SIZE;
	if (fabs(data->player.ray_dir.y) < fabs(data->player.ray_dir.x))
	{
		if (data->player.ray_dir.x > 0)
			direction = 1;
		else
			direction = -1;
		printf("x is %d\ny is %d\ncharacter is %c\n", x, y, data->map.array[y][x + direction]);
		if (data->map.array[y][x + direction] == 'D')
			data->map.array[y][x + direction] = 'd';
		else if (data->map.array[y][x + direction] == 'd')
			data->map.array[y][x + direction] = 'D';
	}
	else
	{
		if (data->player.ray_dir.y > 0)
			direction = 1;
		else
			direction = -1;
		printf("x is %d\ny is %d\ncharacter is %c\n", x, y, data->map.array[y + direction][x]);
		if (data->map.array[y + direction][x] == 'D')
			data->map.array[y + direction][x] = 'd';
		else if (data->map.array[y + direction][x] == 'd')
			data->map.array[y + direction][x] = 'D';
	}
}

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

// void	render_walls(t_data *data, t_vec ray, double angle)
// {
// 	double		distance;
// 	double		x_offset;
// 	int			game_pos_to_draw;
// 	int			xpm_pos;
// 	t_direction	direction;
// 	t_coord		loop;

// 	distance = sqrt(pow(data->player.pos.x - ray.x, 2) + pow(data->player.pos.y - ray.y, 2)) * cos(angle);
// 	direction = get_direction_of_ray(data->player.direction, angle);
// 	x_offset = get_x_offset_for_tile_position(direction, ray);

// 	//printf("====================\n");
// 	//printf("distance  | %f\n", distance);
// 	//printf("x_scale   | %d\n", X_SCALE);
// 	//printf("y_scale   | %d\n", (int)Y_SCALE(distance));
// 	//printf("direction | %d\n", direction);
// 	//printf("x_offset  | %f\n", x_offset);
// 	//printf("width     | %d\n", data->game.width);
// 	//printf("height    | %d\n", data->game.height);
// 	//printf("====================\n");
// 	loop.x = 0;
// 	while (loop.x < X_SCALE)
// 	{
// 		loop.y = 0;
// 		while (loop.y < Y_SCALE(distance))
// 		{
// 			game_pos_to_draw = data->game.width * (loop.y + data->game.height / 2 - Y_SCALE(distance) / 2)
// 				+ (loop.x + data->game.width / 2 + (int)(angle * 180 / M_PI * 24) - X_SCALE / 2);
			// xpm_pos = XPM_SIZE * (int)((float)loop.y/(float)Y_SCALE(distance) * XPM_SIZE) + (int)x_offset;
			// data->game.img.data[game_pos_to_draw] = data->north_wall.data[xpm_pos];
// 			loop.y++;
// 		}
// 		loop.x++;
// 	}
// }

t_xpm	get_texture(t_data *data, t_math *math, int side)
{
	if (math->door == 1)
		return (data->door);
	if (!side)
	{
		if (math->ray_dir.x < 0)
			return (data->east_wall);
		else
			return (data->west_wall);
	}
	else
	{
		if (math->ray_dir.y < 0)
			return (data->north_wall);
		else
			return (data->south_wall);
	}
}

void	render_walls2(t_data *data, int index, double wall_distance, double wall, int side, t_math *math)
{
	int		j;
	int		game_pos_to_draw;
	int		factor;
	double	xpm_pos;
	t_xpm	img;

	j = 0;
	factor = (TILE_SIZE * 375) / (wall_distance); //height scaling for game
	img = get_texture(data, math, side);
	while (j < factor)
	{
		game_pos_to_draw = data->game.width * (j + (data->game.height / 2)) + (data->game.width - index);
		if (game_pos_to_draw <= data->game.width * data->game.height) //bottom part
		{
			xpm_pos = XPM_SIZE * (round(((float)j/(float)factor) * XPM_SIZE/2 + XPM_SIZE/2)) + ((float)((int)wall % TILE_SIZE)/TILE_SIZE * XPM_SIZE);
			data->game.img.data[game_pos_to_draw] = img.data[(int)xpm_pos];
		}

		game_pos_to_draw = data->game.width * (factor - j + (data->game.height / 2) - 1) + (index);
		if (data->game.width * data->game.height - game_pos_to_draw >= 0) //top part
		{
			xpm_pos = XPM_SIZE * (round(((float)j/(float)factor)/2 * XPM_SIZE)) + ((float)((int)wall % TILE_SIZE)/TILE_SIZE * XPM_SIZE);
			data->game.img.data[data->game.width * data->game.height - game_pos_to_draw] = img.data[(int)xpm_pos];
		}
		j++;
	}
}

void	get_side_magtitude(t_math *math, t_player *player)
{
	if (math->ray_dir.x < 0)
	{
		math->step.x = -1;
		math->side_dist.x = (player->pos.x - math->map_pos.x) * math->delta_dist.x;
	}
	else
	{
		math->step.x = 1;
		math->side_dist.x = (math->map_pos.x + 1.0 - player->pos.x) * math->delta_dist.x;
	}
	if (math->ray_dir.y < 0)
	{
		math->step.y = -1;
		math->side_dist.y = (player->pos.y - math->map_pos.y) * math->delta_dist.y;
	}
	else
	{
		math->step.y = 1;
		math->side_dist.y = (math->map_pos.y + 1.0 - player->pos.y) * math->delta_dist.y;
	}
}

double	execute_dda(t_math *math, t_map *map, int *side)
{
	double	dist;
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (math->side_dist.x < math->side_dist.y) //if hit horizontal side
		{
			math->side_dist.x += math->delta_dist.x;
			math->map_pos.x += math->step.x;
			//map->img.data[map->width * (math->map_pos.y) + (math->map_pos.x)] = get_argb_val(RED, MAP_TRANSPARENCY);
			*side = 0;
		}
		else //if hit vertical side
		{
			math->side_dist.y += math->delta_dist.y;
			math->map_pos.y += math->step.y;
			//map->img.data[map->width * (math->map_pos.y) + (math->map_pos.x)] = get_argb_val(RED, MAP_TRANSPARENCY);
			*side = 1;
		}
		if (map->array[math->map_pos.y / TILE_SIZE][math->map_pos.x / TILE_SIZE] != '0')
		{//check collision
			if (map->array[math->map_pos.y / TILE_SIZE][math->map_pos.x / TILE_SIZE] == 'D')
			{
				hit = 1;
				math->door = 1;
			}
			if (map->array[math->map_pos.y / TILE_SIZE][math->map_pos.x / TILE_SIZE] == '1')
				hit = 1;
		}
	}
	if (*side == 0)
		dist = math->side_dist.x - math->delta_dist.x;
	else
		dist = math->side_dist.y - math->delta_dist.y;
	return (dist);
}

double	wall_collision(t_math *math, t_data *data, int side, double distance)
{
	double	wall;
	if (side == 0)
		wall = data->player.pos.y + distance * math->ray_dir.y;
	else
		wall = data->player.pos.x + distance * math->ray_dir.x;
	return (floor(wall));
}

void	draw_gun(t_data *data, char *path_to_xpm)
{
	t_xpm	texture;
	t_coord	loop;

	//select texture somewhere here;
	// printf("ENTERED WITH %s\n", path_to_xpm);
	init_xpm(data->mlx, &texture, path_to_xpm);
	//texture.img_p = mlx_xpm_file_to_image(data->mlx, path_to_xpm, &texture.width, &texture.height);
	//texture.data = (int *)mlx_get_data_addr(texture.img_p,
	//		&texture.bpp, &texture.line_size, &texture.endian);
	loop.x = 0;
	while (loop.x < GUN_HEIGHT * GUN_X_SCALE)
	{
		loop.y = 0;
		while (loop.y < GUN_WIDTH * GUN_Y_SCALE)
		{
			if (loop.y % GUN_Y_SCALE == 0)
				data->game.gun.data[GUN_WIDTH * GUN_X_SCALE * loop.y + loop.x]
					= texture.data[GUN_WIDTH * (loop.y / GUN_Y_SCALE) + (loop.x / GUN_X_SCALE)];
			else
				data->game.gun.data[GUN_WIDTH * GUN_X_SCALE * loop.y + loop.x]
					= texture.data[GUN_WIDTH * ((loop.y - loop.y % GUN_Y_SCALE) / GUN_Y_SCALE)
					+ ((loop.x - loop.x % GUN_X_SCALE) / GUN_X_SCALE)];
			loop.y++;
		}
		loop.x++;
	}
}

void	draw_game_render(t_data *data)
{
	t_math	math;
	double	wall;
	double	wall_distance;
	int		i;
	int		side;

	i = 1; //to handle overflow on the left side
	while (i < data->game.width)
	{
		math.door = 0;
		math.camera_x = 2 * i / (double)data->game.width - 1;
		math.ray_dir.x = data->player.ray_dir.x + data->player.plane_dir.x * math.camera_x;
		math.ray_dir.y = data->player.ray_dir.y + data->player.plane_dir.y * math.camera_x;
		math.delta_dist.x = fabs(1 / (math.ray_dir.x));
		math.delta_dist.y = fabs(1 / (math.ray_dir.y));
		math.map_pos.x = (int)data->player.pos.x;
		math.map_pos.y = (int)data->player.pos.y;
		get_side_magtitude(&math, &data->player);
		wall_distance = execute_dda(&math, &data->map, &side);
		wall = wall_collision(&math, data, side, wall_distance);
		render_walls2(data, i, wall_distance, wall, side, &math);
		i++;
	}
}

void	shoot_gun(t_data *data)
{
	int	 i;

	i = 0;
	draw_gun(data, "./textures/Gun_02.xpm");
	mlx_put_image_to_window(data->mlx, data->win, data->game.gun.img_p, WINDOW_WIDTH / 2 - (GUN_WIDTH * GUN_X_SCALE)/2 - 50, WINDOW_HEIGHT - (GUN_HEIGHT * GUN_Y_SCALE));
	mlx_put_image_to_window(data->mlx, data->win, data->game.background.img_p, 0, WINDOW_HEIGHT - XPM_SIZE * HUD_Y_SCALE);
	while (i++ < 50)
		;
	draw_gun(data, "./textures/Gun_03.xpm");
	mlx_put_image_to_window(data->mlx, data->win, data->game.gun.img_p, WINDOW_WIDTH / 2 - (GUN_WIDTH * GUN_X_SCALE)/2 - 50, WINDOW_HEIGHT - (GUN_HEIGHT * GUN_Y_SCALE));
	mlx_put_image_to_window(data->mlx, data->win, data->game.background.img_p, 0, WINDOW_HEIGHT - XPM_SIZE * HUD_Y_SCALE);
	i = 0;
	while (i++ < 50)
		;
	draw_gun(data, "./textures/Gun_04.xpm");
	mlx_put_image_to_window(data->mlx, data->win, data->game.gun.img_p, WINDOW_WIDTH / 2 - (GUN_WIDTH * GUN_X_SCALE)/2 - 50, WINDOW_HEIGHT - (GUN_HEIGHT * GUN_Y_SCALE));
	mlx_put_image_to_window(data->mlx, data->win, data->game.background.img_p, 0, WINDOW_HEIGHT - XPM_SIZE * HUD_Y_SCALE);
	i = 0;
	while (i++ < 50)
		;
}

void	draw_hud(t_data *data)
{
	t_xpm	background_tex;
	t_coord	loop;
	int		x_scale;

	init_xpm(data->mlx, &background_tex, "./textures/Steel_2A.xpm");
	x_scale = round((float)data->game.width / XPM_SIZE);
	loop.x = 0;
	while (loop.x < XPM_SIZE * x_scale)
	{
		loop.y = 0;
		while (loop.y < XPM_SIZE * HUD_Y_SCALE)
		{
			if (loop.y % HUD_Y_SCALE == 0)
				data->game.background.data[data->game.width * loop.y + loop.x]
					= background_tex.data[XPM_SIZE * (loop.y / HUD_Y_SCALE) + (loop.x / x_scale)];
			else
				data->game.background.data[data->game.width * loop.y + loop.x]
					= background_tex.data[XPM_SIZE * ((loop.y - loop.y % HUD_Y_SCALE) / HUD_Y_SCALE)
					+ ((loop.x - loop.x % x_scale) / x_scale)];
			loop.y++;
		}
		loop.x++;
	}
}

void	draw_game(t_data *data)
{
	draw_game_render(data);
	draw_gun(data, "./textures/Gun_01.xpm");
	draw_hud(data);
}

t_game	game_init(void *mlx)
{
	t_game	game;

	game.fps = 0;
	game.shot = 0;
	game.draw_game = draw_game;
	game.width = WINDOW_WIDTH;
	game.height = WINDOW_HEIGHT;
	game.draw_sky = draw_sky;
	game.shoot_gun = shoot_gun;
	game.img.img_p = mlx_new_image(mlx, game.width, game.height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img_p,
			&game.img.bpp, &game.img.line_size, &game.img.endian);

	game.gun.img_p = mlx_new_image(mlx, GUN_WIDTH * GUN_X_SCALE, GUN_HEIGHT * GUN_Y_SCALE);
	game.gun.data = (int *)mlx_get_data_addr(game.gun.img_p,
			&game.gun.bpp, &game.gun.line_size, &game.gun.endian);

	game.background.img_p = mlx_new_image(mlx, game.width, XPM_SIZE * HUD_Y_SCALE);
	game.background.data = (int *)mlx_get_data_addr(game.background.img_p,
			&game.background.bpp, &game.background.line_size, &game.background.endian);
	return (game);
}
