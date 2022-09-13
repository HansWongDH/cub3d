/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:24:57 by wding-ha          #+#    #+#             */
/*   Updated: 2021/06/01 17:14:01 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	srcl;
	size_t	dstl;
	size_t	ret;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (n <= 0)
		return (srcl + n);
	if (n <= dstl)
		ret = srcl + n;
	else
		ret = srcl + dstl;
	srcl = 0;
	while (dstl < (n - 1) && src[srcl])
		dst[dstl++] = src[srcl++];
	dst[dstl] = '\0';
	return (ret);
}
