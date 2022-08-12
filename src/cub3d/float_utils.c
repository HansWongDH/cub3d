/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:52:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/12 14:52:49 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		equate_float(float a, float b)
{
	return (fabs(a - b) < FLT_EPSILON);
}

int		greater_than_float(float a, float b)
{
	return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * FLT_EPSILON);
}

int		less_than_float(float a, float b)
{
	return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * FLT_EPSILON);
}

float	get_positive_value_of_angle(float angle)
{
	if (equate_float(angle, 2 * PI))
		return (0);
	if (greater_than_float(angle, 2 * PI))
		return (angle - (2 * PI));
	if (less_than_float(angle, 0))
		return (angle + (2 * PI));
	return (angle);
}

