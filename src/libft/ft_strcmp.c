/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:00:06 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 19:02:09 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp( const char *s1, const char *s2)
{
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
