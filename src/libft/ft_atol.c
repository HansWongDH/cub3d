/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:09:06 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 20:09:21 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	i;
	int		sign;

	sign = 1;
	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		i = i * 10 + (*str - '0');
		str++;
		if (i != (i * 2) / 2 && sign > 0)
			return (-1);
		if (i != (i * 2) / 2 && sign < 0)
			return (0);
	}
	return (sign * i);
}
