/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:10:30 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/30 15:05:01 by wding-ha         ###   ########.fr       */
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

int	map_filetype(char *file)
{
	char	*file_type;

	if (ft_strlen(file) < 5)
		return (0);
	file_type = ft_substr(file, ft_strlen(file) - 4, 4);
	if (ft_strcmp(file_type, ".cub"))
	{
		free(file_type);
		return (0);
	}
	free(file_type);
	return (1);
}

void	map_skip_element(int fd, int index)
{
	char	*line;

	while (index > 0)
	{
		get_next_line(fd, &line);
		free(line);
		index--;
	}
}