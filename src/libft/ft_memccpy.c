/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:27:55 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 16:25:42 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstm;
	unsigned char	*srcm;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dstm = (unsigned char *)dest;
	srcm = (unsigned char *)src;
	while (i < n)
	{
		dstm[i] = srcm[i];
		if (dstm[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
