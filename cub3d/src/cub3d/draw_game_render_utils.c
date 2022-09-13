/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_render_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:35:20 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 13:36:08 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	get_xpm_pos(t_xpm *img, double scale, double wall, int option)
{
	t_vec	coord;

	if (option == 0)
	{
		coord.y = round(scale
				* ((img->height - 1) / 2) + ((img->height - 1) / 2));
		coord.x = round((double)(img->width - 1) * wall);
		return (img->width * coord.y + coord.x);
	}
	coord.y = round(scale / 2 * (img->height - 1));
	coord.x = round((double)(img->width - 1) * wall);
	return (img->width * coord.y + coord.x);
}

int	get_pos_to_draw(t_data *data, int factor, int j, int index)
{
	t_coord	coord;

	if (factor == -1)
	{
		coord.y = j + (data->game.height / 2);
		coord.x = data->game.width - index;
		return (data->game.width * coord.y + coord.x);
	}
	coord.y = factor - j + (data->game.height / 2) - 1;
	coord.x = index;
	return (data->game.width * coord.y + coord.x);
}

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

void	flag_collision(t_math *math, char **array, int *hit)
{
	if (array[math->map_pos.y / TILE_SIZE][math->map_pos.x / TILE_SIZE] != '0')
	{
		if (array[math->map_pos.y / TILE_SIZE]
			[math->map_pos.x / TILE_SIZE] == 'D')
		{
			*hit = 1;
			math->door = 1;
		}
		if (array[math->map_pos.y / TILE_SIZE]
			[math->map_pos.x / TILE_SIZE] == '1')
			*hit = 1;
	}
}

int	check_side(t_math *math)
{
	if (math->side_dist.x < math->side_dist.y)
	{
		math->side_dist.x += math->delta_dist.x;
		math->map_pos.x += math->step.x;
		return (0);
	}
	math->side_dist.y += math->delta_dist.y;
	math->map_pos.y += math->step.y;
	return (1);
}
