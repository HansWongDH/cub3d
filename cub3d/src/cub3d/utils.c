/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:23 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 14:18:41 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	get_argb_val(int colour, int transparency)
{
	float	trasparency_percentage;
	int		col_in_argb;

	if (transparency < 0 || transparency > 100)
		return (colour);
	trasparency_percentage = (float)transparency / 100 * 255;
	col_in_argb = colour | ((int)trasparency_percentage << 24);
	return (col_in_argb);
}

int	is_movement_keys(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		return (1);
	if (keycode == KEY_U_ARROW || keycode == KEY_R_ARROW
		|| keycode == KEY_D_ARROW || keycode == KEY_L_ARROW)
		return (2);
	return (0);
}

int	shade_colour(int colour, int percent)
{
	int	i;

	i = 0;
	while (i++ < percent)
		colour = ((colour & 0x7E7E7E) >> 1) | (colour & 0x808080);
	return (colour);
}

int	free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}
