/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:40:49 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 16:25:23 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n, int sign)
{
	int	len;

	len = 0;
	if (sign < 0)
		len = 1;
	if (n == 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*hold;
	long	num;

	sign = 1;
	num = (long)n;
	if (num < 0)
		sign *= -1;
	num *= sign;
	i = ft_intlen(num, sign);
	hold = ft_calloc(i + 1, 1);
	if (!hold)
		return (NULL);
	if (sign < 0)
		hold[0] = '-';
	if (n == 0)
		hold[0] = '0';
	while (num)
	{
		hold[i-- - 1] = '0' + (num % 10);
		num /= 10;
	}
	return (hold);
}
