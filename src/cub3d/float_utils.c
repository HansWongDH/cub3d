/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:52:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/17 12:49:42 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		equate_float(float a, float b)
{
	return (fabs(a - b) < FLT_EPSILON); //idk why this is fabs instead of fabsf
}

int		greater_than_float(float a, float b)
{
	return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * FLT_EPSILON);
}

int		less_than_float(float a, float b)
{
	return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * FLT_EPSILON);
}

int		equate_double(double a, double b)
{
	return (fabs(a - b) < DBL_EPSILON);
}

int		greater_than_double(float a, float b)
{
	return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * DBL_EPSILON);
}

int		less_than_double(float a, float b)
{
	return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * DBL_EPSILON);
}

float	get_positive_value_of_angle(double angle) //move to other file
{
	//if (equate_float(angle, 2 * M_PI))
	//	return (0);
	//if (greater_than_float(angle, 2 * M_PI))
	//	return (angle - (2 * M_PI));
	//if (less_than_float(angle, 0))
	//	return (angle + (2 * M_PI));
	if (equate_double(angle, 2 * M_PI))
		return (0);
	if (greater_than_double(angle, 2 * M_PI))
		return (angle - (2 * M_PI));
	if (less_than_double(angle, 0))
		return (angle + (2 * M_PI));
	return (angle);
}
