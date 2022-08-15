/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/15 20:27:35 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

float		get_player_direction_angle(int player_direction)
{
	if (player_direction == 'N')
		return (3 * M_PI / 2);
	if (player_direction == 'E')
		return (0);
	if (player_direction == 'S')
		return (M_PI / 2);
	return (M_PI);
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
				+ (int)floor(ray.x)] == GREEN)
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
	if (keycode == KEY_A)
	{
		self->direction -= ROTATE_FACTOR;
		self->direction = get_positive_value_of_angle(self->direction);
		self->ray_dir.x = cos(self->direction);
		self->ray_dir.y = sin(self->direction);
	}
	else if (keycode == KEY_D)
	{
		self->direction += ROTATE_FACTOR;
		self->direction = get_positive_value_of_angle(self->direction);
		self->ray_dir.x = cos(self->direction);
		self->ray_dir.y = sin(self->direction);
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
	player.direction = get_player_direction_angle(player_direction);
	player.ray_dir.x = cos(player.direction);
	player.ray_dir.y = sin(player.direction);
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
