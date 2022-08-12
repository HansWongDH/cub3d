/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:31:29 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/03 17:58:06 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freestr(char **str)
{
	if (str || *str)
	{
		free(*str);
		*str = NULL;
	}
}

int	processline(char **save, char **line, int ret)
{
	int		len;
	char	*hold;

	if (ret < 0)
		return (-1);
	len = 0;
	while ((*save)[len] && (*save)[len] != '\n')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		hold = ft_strdup(&((*save)[len + 1]));
		freestr(save);
		*save = hold;
	}
	else
	{
		*line = ft_strdup(*save);
		freestr(save);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[20];
	static char	*save;
	int			ret;
	char		*str;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, 20);
		if (ret < 0)
			break ;
		if (!save)
			save = ft_calloc(1, 1);
		buf[ret] = '\0';
		str = ft_strjoin(save, buf);
		freestr(&save);
		save = str;
		if ((ft_strchr(save, '\n')))
			return (processline(&save, line, ret));
	}
	return (processline(&save, line, ret));
}
