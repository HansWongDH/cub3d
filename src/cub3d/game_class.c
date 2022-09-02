/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:40:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 13:45:31 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_sky(t_game *self, unsigned int floor_col, unsigned int ciel_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < self->width)
	{
		j = 0;
		while (j < self->height)
		{
			if (j > self->height / 2)
				self->img.data[self->width * j + i] = floor_col;
			else
				self->img.data[self->width * j + i] = ciel_col;
			j++;
		}
		i++;
	}
}

void	open_door(t_data *data)
{
	int		direction;
	t_coord	coord;

	coord = equate_coords_int(data->player.pos.x / TILE_SIZE,
			data->player.pos.y / TILE_SIZE);
	if (fabs(data->player.ray_dir.y) < fabs(data->player.ray_dir.x))
	{
		if (data->player.ray_dir.x > 0)
			direction = 1;
		else
			direction = -1;
		toggle_door(data->map.array, coord.x + direction, coord.y);
	}
	else
	{
		if (data->player.ray_dir.y > 0)
			direction = 1;
		else
			direction = -1;
		toggle_door(data->map.array, coord.x, coord.y + direction);
	}
}

void	shoot_gun(t_data *data)
{
	int	i;
	int	frames;

	i = 0;
	frames = 50;
	draw_gun(data, "./textures/Gun_02.xpm");
	put_gun_and_hud_image(data);
	while (i++ < frames)
		;
	draw_gun(data, "./textures/Gun_03.xpm");
	put_gun_and_hud_image(data);
	i = 0;
	while (i++ < frames)
		;
	draw_gun(data, "./textures/Gun_04.xpm");
	put_gun_and_hud_image(data);
	i = 0;
	while (i++ < frames)
		;
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

	game.draw_game = draw_game;
	game.width = WINDOW_WIDTH;
	game.height = WINDOW_HEIGHT;
	game.draw_sky = draw_sky;
	game.shoot_gun = shoot_gun;
	game.open_door = open_door;
	game.img.img_p = mlx_new_image(mlx, game.width, game.height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img_p,
			&game.img.bpp, &game.img.line_size, &game.img.endian);
	game.gun.img_p = mlx_new_image(mlx, GUN_WIDTH * GUN_X_SCALE,
			GUN_HEIGHT * GUN_Y_SCALE);
	game.gun.data = (int *)mlx_get_data_addr(game.gun.img_p,
			&game.gun.bpp, &game.gun.line_size, &game.gun.endian);
	game.background.img_p = mlx_new_image(mlx, game.width,
			XPM_SIZE * HUD_Y_SCALE);
	game.background.data = (int *)mlx_get_data_addr(game.background.img_p,
			&game.background.bpp, &game.background.line_size,
			&game.background.endian);
	return (game);
}
