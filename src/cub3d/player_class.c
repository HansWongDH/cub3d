/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:28 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/11 17:12:15 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void		turn_player(t_player *self, int keycode)
{
	if (keycode == KEY_A)
	{
		self->player_direction -= ROTATE_FACTOR;
		self->player_direction = get_positive_value_of_angle(self->player_direction);
		self->ray_dir.x = cos(self->player_direction);
		self->ray_dir.y = sin(self->player_direction);
	}
	else if (keycode == KEY_D)
	{
		self->player_direction += ROTATE_FACTOR;
		self->player_direction = get_positive_value_of_angle(self->player_direction);
		self->ray_dir.x = cos(self->player_direction);
		self->ray_dir.y = sin(self->player_direction);
	}
}

void		move_player(t_player *self, int keycode)
{
	if (keycode == KEY_W)
	{
		//validate_move(self->pos.x, self->pos.y, KEY_W);
		self->pos.x += self->ray_dir.x * MOVE_GAP;
		self->pos.y += self->ray_dir.y * MOVE_GAP;
	}
	else if (keycode == KEY_S)
	{
		//validate_move(self->pos.x, self->pos.y, KEY_S);
		self->pos.x -= self->ray_dir.x * MOVE_GAP;
		self->pos.y -= self->ray_dir.y * MOVE_GAP;
	}
}

void		print_player(t_player *self)
{
	printf("===================================\n");
	printf("player pos x           : %f\n", self->pos.x);
	printf("pleyer pos y           : %f\n", self->pos.y);
	printf("player direction       : %0.4f\n", self->player_direction);
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
	player.pos.x = 80;
	player.pos.y = 80;
	player.player_direction = 0;
	player.ray_dir.x = cos(player.player_direction);
	player.ray_dir.y = sin(player.player_direction);
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
