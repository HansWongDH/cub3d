/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/24 16:03:30 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	turn_player(t_player *self, int keycode)
{
	double	oldray_dir_x;
	//double	oldplane_dirX;

	oldray_dir_x = self->ray_dir.x;
	//oldplane_dirX = self->plane_dir.x;
	if (keycode == KEY_A)
	{
		self->ray_dir = equate_vectors_double(
				self->ray_dir.x * cos(-ROTATE_FACTOR) - self->ray_dir.y * sin(-ROTATE_FACTOR),
				oldray_dir_x * sin(-ROTATE_FACTOR) + self->ray_dir.y * cos(-ROTATE_FACTOR));
		self->plane_dir = get_plane_dir(self->ray_dir);
		//self->ray_dir.x = self->ray_dir.x * cos(-ROTATE_FACTOR) - self->ray_dir.y * sin(-ROTATE_FACTOR);
		//self->ray_dir.y = oldray_dir_x * sin(-ROTATE_FACTOR) + self->ray_dir.y * cos(-ROTATE_FACTOR);
		//self->plane_dir.x = self->plane_dir.x * cos(-ROTATE_FACTOR) - self->plane_dir.y * sin(-ROTATE_FACTOR);
		//self->plane_dir.y = oldplane_dirX * sin(-ROTATE_FACTOR) + self->plane_dir.y * cos(-ROTATE_FACTOR);
	}
	else if (keycode == KEY_D)
	{
		self->ray_dir = equate_vectors_double(
				self->ray_dir.x * cos(ROTATE_FACTOR) - self->ray_dir.y * sin(ROTATE_FACTOR),
				oldray_dir_x * sin(ROTATE_FACTOR) + self->ray_dir.y * cos(ROTATE_FACTOR));
		self->plane_dir = get_plane_dir(self->ray_dir);
		//self->ray_dir.x = self->ray_dir.x * cos(ROTATE_FACTOR) - self->ray_dir.y * sin(ROTATE_FACTOR);
		//self->ray_dir.y = oldray_dir_x * sin(ROTATE_FACTOR) + self->ray_dir.y * cos(ROTATE_FACTOR);
		//self->plane_dir.x = self->plane_dir.x * cos(ROTATE_FACTOR) - self->plane_dir.y * sin(ROTATE_FACTOR);
		//self->plane_dir.y = oldplane_dirX * sin(ROTATE_FACTOR) + self->plane_dir.y * cos(ROTATE_FACTOR);
	}
	else if (keycode == KEY_U_ARROW)
	{
		self->ray_dir = get_player_direction_angle('N');
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
	else if (keycode == KEY_R_ARROW)
	{
		self->ray_dir = get_player_direction_angle('E');
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
	else if (keycode == KEY_D_ARROW)
	{
		self->ray_dir = get_player_direction_angle('S');
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
	else if (keycode == KEY_L_ARROW)
	{
		self->ray_dir = get_player_direction_angle('W');
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
}

void	move_player(t_player *self, int keycode, t_map *map)
{
	if (keycode == KEY_W)
	{
		if (validate_move(self, map, KEY_W) == 0)
			return ;
		self->pos = add_vectors_double(self->pos,
				self->ray_dir.x * MOVE_GAP, self->ray_dir.y * MOVE_GAP);
	}
	else if (keycode == KEY_S)
	{
		if (validate_move(self, map, KEY_S) == 0)
			return ;
		self->pos = subtract_vectors_double(self->pos,
				self->ray_dir.x * MOVE_GAP, self->ray_dir.y * MOVE_GAP);
	}
}

void	print_player(t_player *self)
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
	player.plane_dir = get_plane_dir(player.ray_dir);
	player.size = TILE_SIZE / 2;
	player.print_player(&player);
	return (player);
}
