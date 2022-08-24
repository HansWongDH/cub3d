/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:31:49 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/24 15:30:26 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_class.h"

t_vec	get_player_direction_angle(int player_direction)
{
	t_vec	vec;

	if (player_direction == 'N')
		vec = equate_vectors_double(0, -1);
	else if (player_direction == 'E')
		vec = equate_vectors_double(1, 0);
	else if (player_direction == 'S')
		vec = equate_vectors_double(0, 1);
	else
		vec = equate_vectors_double(-1, 0);
	return (vec);
}

t_vec	get_plane_dir(t_vec ray_dir)
{
	t_vec	plane_dir;

	plane_dir = equate_vectors_double(0.66 * ray_dir.y, -(0.66 * ray_dir.x));
	return (plane_dir);
}

int	validate_move(t_player *player, t_map *map, int keycode)
{
	t_vec	ray;
	t_vec	delta;
	double	max;
	int		i;

	i = 0;
	ray = equate_vectores(player->pos);
	delta = equate_vectors_double(
			cos(0) * player->ray_dir.x - sin(0) * player->ray_dir.y,
			sin(0) * player->ray_dir.x + cos(0) * player->ray_dir.y);
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta = divide_vectors_double(delta, max, max);
	while (i < 12)
	{
		if (map->img.data[map->width * (int)floor(ray.y)
				+ (int)floor(ray.x)]
			== (int)get_argb_val(WALLCOL, MAP_TRANSPARENCY))
			return (0);
		if (keycode == KEY_S)
			ray = subtract_vectors(ray, delta);
		else
			ray = add_vectors(ray, delta);
		i++;
	}
	return (1);
}
