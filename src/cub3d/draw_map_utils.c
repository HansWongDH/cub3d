/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:24:05 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/30 11:40:57 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_square(int *img_data, t_coord tile_coord, int width, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			img_data[width * (i + tile_coord.x * TILE_SIZE)
				+ (j + tile_coord.y * TILE_SIZE)] = colour;
			j++;
		}
		i++;
	}
}
