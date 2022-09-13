/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:31:40 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 09:33:26 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_vec	add_vectors_double(t_vec v1, double x, double y)
{
	t_vec	res;

	res.x = (v1.x + x);
	res.y = (v1.y + y);
	return (res);
}

t_vec	subtract_vectors_double(t_vec v1, double x, double y)
{
	t_vec	res;

	res.x = (v1.x - x);
	res.y = (v1.y - y);
	return (res);
}

t_vec	equate_vectors_double(double x, double y)
{
	t_vec	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vec	divide_vectors_double(t_vec v1, double x, double y)
{
	t_vec	res;

	res.x = (v1.x / x);
	res.y = (v1.y / y);
	return (res);
}
