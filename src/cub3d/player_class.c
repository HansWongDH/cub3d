/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/12 18:55:27 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int			validate_move(t_player *player, int *map_data, int keycode)
{
	double	to_move_x;
	double	to_move_y;
	int		wall_padding;

	wall_padding = 8;
	if (keycode == KEY_W)
	{
		to_move_x = (player->pos.x + player->ray_dir.x * (MOVE_GAP + wall_padding));
		to_move_y = (player->pos.y + player->ray_dir.y * (MOVE_GAP + wall_padding));
		if (map_data[WIDTH * (int)(to_move_y)
				+ (int)(to_move_x)] == GREEN)
			return (0);
	}
	else if (keycode == KEY_S)
	{
		to_move_x = (player->pos.x - player->ray_dir.x * MOVE_GAP + wall_padding);
		to_move_y = (player->pos.y - player->ray_dir.y * MOVE_GAP + wall_padding);
		if (map_data[WIDTH * (int)(to_move_y)
				+ (int)(to_move_x)] == GREEN)
			return (0);
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

void		move_player(t_player *self, int *map_data, int keycode)
{
	if (keycode == KEY_W)
	{
		if (validate_move(self, map_data, KEY_W) == 0)
			return ;
		self->pos.x += self->ray_dir.x * MOVE_GAP;
		self->pos.y += self->ray_dir.y * MOVE_GAP;
	}
	else if (keycode == KEY_S)
	{
		if (validate_move(self, map_data, KEY_S) == 0)
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

t_player	player_init(void)
{
	t_player	player;

	player.move_player = move_player;
	player.print_player = print_player;
	player.turn_player = turn_player;
	player.pos.x = 208;
	player.pos.y = 208;
	player.direction = 5 * M_PI / 4;
	player.ray_dir.x = cos(player.direction);
	player.ray_dir.y = sin(player.direction);
	player.size = 3;
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
