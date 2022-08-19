/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/18 14:39:54 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

t_vec	get_player_direction_angle(int player_direction)
{
	t_vec	vec;

	if (player_direction == 'N')
	{
		vec.x = 0;
		vec.y = -1;
	}
	else if (player_direction == 'E')
	{
		vec.x = 1;
		vec.y = 0;
	}
	else if (player_direction == 'S')
	{
		vec.x = 0;
		vec.y = 1;
	}
	else
	{
		vec.x = -1;
		vec.y = 0;
	}
	return (vec);
}

int				validate_move(t_player *player, t_map *map, int keycode)
{
	t_vec	ray;
	t_vec	delta;
	double	max;
	int		i;

	i = 0;
	ray.x = player->pos.x;
	ray.y = player->pos.y;
	delta.x = cos(0) * player->ray_dir.x - sin(0) * player->ray_dir.y;
	delta.y = sin(0) * player->ray_dir.x + cos(0) * player->ray_dir.y;
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta.x /= max;
	delta.y /= max;
	while (i < 12)
	{
		if (map->img.data[map->width * (int)floor(ray.y)
				+ (int)floor(ray.x)] == (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			return (0);
		if (keycode == KEY_S)
		{
			ray.x -= delta.x;
			ray.y -= delta.y;
		}
		else
		{
			ray.x += delta.x;
			ray.y += delta.y;
		}
		i++;
	}
	return (1);
}

void		turn_player(t_player *self, int keycode)
{
	double	oldray_dirX;
	double	oldplane_dirX;

	oldray_dirX = self->ray_dir.x;
	oldplane_dirX = self->plane_dir.x;
	if (keycode == KEY_A)
	{
		self->ray_dir.x =  self->ray_dir.x * cos(-ROTATE_FACTOR) - self->ray_dir.y * sin(-ROTATE_FACTOR);
		self->ray_dir.y = oldray_dirX * sin(-ROTATE_FACTOR) + self->ray_dir.y * cos(-ROTATE_FACTOR);
		self->plane_dir.x = self->plane_dir.x * cos(-ROTATE_FACTOR) - self->plane_dir.y * sin(-ROTATE_FACTOR);
		self->plane_dir.y = oldplane_dirX * sin(-ROTATE_FACTOR) + self->plane_dir.y * cos(-ROTATE_FACTOR);
	}
	else if (keycode == KEY_D)
	{
		self->ray_dir.x =  self->ray_dir.x * cos(ROTATE_FACTOR) - self->ray_dir.y * sin(ROTATE_FACTOR);
		self->ray_dir.y = oldray_dirX * sin(ROTATE_FACTOR) + self->ray_dir.y * cos(ROTATE_FACTOR);
		self->plane_dir.x = self->plane_dir.x * cos(ROTATE_FACTOR) - self->plane_dir.y * sin(ROTATE_FACTOR);
		self->plane_dir.y = oldplane_dirX * sin(ROTATE_FACTOR) + self->plane_dir.y * cos(ROTATE_FACTOR);
	}
}

void		move_player(t_player *self, int *map_data, int keycode, t_map *map)
{
	(void)map_data;
	if (keycode == KEY_W)
	{
		if (validate_move(self, map, KEY_W) == 0)
			return ;
		self->pos.x += self->ray_dir.x * MOVE_GAP;
		self->pos.y += self->ray_dir.y * MOVE_GAP;
	}
	else if (keycode == KEY_S)
	{
		if (validate_move(self, map, KEY_S) == 0)
			return ;
		self->pos.x -= self->ray_dir.x * MOVE_GAP;
		self->pos.y -= self->ray_dir.y * MOVE_GAP;
	}
}

void		print_player(t_player *self)
{
	printf("===================================\n");
	printf("player pos x           : %f\n", self->pos.x);
	printf("pleyer pos y           : %f\n", self->pos.y);
	printf("player direction       : %0.4f\n", self->direction);
	printf("player ray direction x : %f\n", self->ray_dir.x);
	printf("player ray direction y : %f\n", self->ray_dir.y);
	printf("plane dir x            : %f\n", self->plane_dir.x);
	printf("plane dir y            : %f\n", self->plane_dir.y);
	printf("===================================\n");
}

t_player	player_init(t_coord player_pos, int player_direction)
{
	t_player	player;

	player.move_player = move_player;
	player.print_player = print_player;
	player.turn_player = turn_player;
	player.pos.x = ((player_pos.x + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	player.pos.y = ((player_pos.y + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	player.ray_dir = get_player_direction_angle(player_direction);
	player.plane_dir.x = fabs(0.66 * player.ray_dir.y);
	player.plane_dir.y = fabs(0.66 * player.ray_dir.x);
	player.size = 6;
	player.print_player(&player);
	return (player);
}

//int	main()
//{
//	t_player	player;
//
//	player = player_init();
//	player.print_player(&player);
//	player.turn_player(&player, KEY_A);
//	player.print_player(&player);
//	player.turn_player(&player, KEY_D);
//	player.print_player(&player);
//	player.turn_player(&player, KEY_D);
//	player.print_player(&player);
//}
