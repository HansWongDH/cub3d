/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:51:58 by wding-ha          #+#    #+#             */
/*   Updated: 2021/06/03 19:28:12 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	searchchr(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ret;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && searchchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && searchchr(set, s1[end - 1]))
		end--;
	ret = malloc(sizeof(char) * end - start + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ret[i++] = s1[start++];
	}
	ret[i] = '\0';
	return (ret);
}
