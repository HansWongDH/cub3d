/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:10:30 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/29 20:01:53 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_2d(char **s)
{
	int	i;
	i = 0;
	
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

int	print_error(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return (1);
}
