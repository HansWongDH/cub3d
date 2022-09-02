/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 14:34:33 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	turn_player_mouse(t_player *self, double m_pos)
{
	double	oldray_dir_x;

	oldray_dir_x = self->ray_dir.x;
	self->ray_dir = equate_vectors_double(
			self->ray_dir.x * cos(m_pos * (M_PI / 2) * SENSITIVITY)
			- self->ray_dir.y * sin(m_pos * (M_PI / 2) * SENSITIVITY),
			oldray_dir_x * sin(m_pos * (M_PI / 2) * SENSITIVITY)
			+ self->ray_dir.y * cos(m_pos * (M_PI / 2) * SENSITIVITY));
	self->plane_dir = get_plane_dir(self->ray_dir);
}

void	turn_player(t_player *self, int keycode)
{
	double	oldray_dir_x;

	oldray_dir_x = self->ray_dir.x;
	if (keycode == KEY_A)
	{
		self->ray_dir = equate_vectors_double(
				self->ray_dir.x * cos(-ROTATE_FACTOR)
				- self->ray_dir.y * sin(-ROTATE_FACTOR),
				oldray_dir_x * sin(-ROTATE_FACTOR)
				+ self->ray_dir.y * cos(-ROTATE_FACTOR));
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
	else if (keycode == KEY_D)
	{
		self->ray_dir = equate_vectors_double(
				self->ray_dir.x * cos(ROTATE_FACTOR)
				- self->ray_dir.y * sin(ROTATE_FACTOR),
				oldray_dir_x * sin(ROTATE_FACTOR)
				+ self->ray_dir.y * cos(ROTATE_FACTOR));
		self->plane_dir = get_plane_dir(self->ray_dir);
	}
	else if (is_movement_keys(keycode) == 2)
		turn_player_arrow_keys(self, keycode);
}

void	move_player(t_player *self, int keycode, t_map *map)
{
	t_vec	temp;

	if (validate_move(self, map, keycode) == 0)
		return ;
	if (keycode == KEY_A || keycode == KEY_D)
		temp = equate_vectors_double(
				self->ray_dir.x * (cos(M_PI_2)) - self->ray_dir.y * sin(M_PI_2),
				self->ray_dir.y * (cos(M_PI_2)) + self->ray_dir.x * sin(M_PI_2)
				);
	else
		temp = equate_vectores(self->ray_dir);
	if (keycode == KEY_W || keycode == KEY_D)
		self->pos = add_vectors_double(self->pos,
				temp.x * MOVE_GAP, temp.y * MOVE_GAP);
	else
		self->pos = subtract_vectors_double(self->pos,
				temp.x * MOVE_GAP, temp.y * MOVE_GAP);
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
	player.turn_player_mouse = turn_player_mouse;
	player.pos.x = ((player_pos.x + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	player.pos.y = ((player_pos.y + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	player.ray_dir = get_player_direction_angle(player_direction);
	player.plane_dir = get_plane_dir(player.ray_dir);
	player.size = TILE_SIZE / 2;
	player.print_player(&player);
	return (player);
}
