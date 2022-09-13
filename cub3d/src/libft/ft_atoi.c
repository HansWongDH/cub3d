/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:36 by wding-ha          #+#    #+#             */
/*   Updated: 2021/06/01 17:41:57 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
	return ((long)sign * i);
}
