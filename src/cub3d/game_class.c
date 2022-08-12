/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:40:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/12 18:22:26 by nfernand         ###   ########.fr       */
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

t_game	game_init(t_map *map, void *mlx)
{
	t_game	game;

	game.height = map->height * 3; //i have no idea why its 3
	game.width = map->width * 3;
	game.draw_sky = draw_sky;
	game.img.img_p = mlx_new_image(mlx, game.width, game.height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img_p,
			&game.img.bpp, &game.img.line_size, &game.img.endian);
	return (game);
}
