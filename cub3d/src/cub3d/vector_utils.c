/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:41:22 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/01 09:32:05 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_vec	add_vectors(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

t_vec	subtract_vectors(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

t_vec	equate_vectores(t_vec v1)
{
	t_vec	res;

	res = v1;
	return (res);
}
