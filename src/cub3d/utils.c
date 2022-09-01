/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:23 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 09:22:04 by nfernand         ###   ########.fr       */
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
