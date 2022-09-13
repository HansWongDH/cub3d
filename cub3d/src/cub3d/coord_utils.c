/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:56:09 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/29 16:15:40 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_coord	add_coords(t_coord c1, t_coord c2)
{
	t_coord	res;

	res.x = c1.x + c2.x;
	res.y = c1.y + c2.y;
	return (res);
}

t_coord	equate_coords_int(int x, int y)
{
	t_coord	res;

	res.x = x;
	res.y = y;
	return (res);
}
