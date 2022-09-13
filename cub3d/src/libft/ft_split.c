/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:32:34 by wding-ha          #+#    #+#             */
/*   Updated: 2021/06/03 19:27:44 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	freemalloc(char **arr, int sep)
{
	sep -= 1;
	while (sep >= 0)
	{
		free(arr[sep]);
		sep--;
	}
	free(arr);
	return (0);
}

int	numstr(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	if (s[i] != c && s[i] != '\0')
		len = 1;
	else
		len = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			len++;
		i++;
	}
	return (len);
}

int	splitloc(char const *s, char c, char **arr, int sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	while (i < sep)
	{
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (len != 0)
		{
			str = ft_calloc(len + 1, 1);
			if (!str)
				return (freemalloc(arr, i));
			arr[i] = ft_memcpy(str, s, len);
			i++;
			s += len + 1;
		}
		while (*s == c)
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;

	if (!s)
		return (NULL);
	size = numstr((char *)s, c);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	if (splitloc(s, c, arr, size) != 1)
		return (NULL);
	arr[size] = NULL;
	return (arr);
}
