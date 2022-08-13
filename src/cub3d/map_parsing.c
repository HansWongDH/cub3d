/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/13 16:53:27 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);

void	map_info_init(t_info *data)
{
	data->player_direction = 0;
	data->width = 0;
	data->height = 0;
}

int	map_filetype(char *s)
{
	char	*file;

	if (ft_strlen(s) < 5)
		return (0);
	file = ft_substr(s, ft_strlen(s) - 4, 4);
	if (ft_strcmp(file, ".cub"))
	{
		free(file);
		return (0);
	}
	free(file);
	return (1);
}

int	map_character_checking(char *line, t_info *data)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (!ft_strchr("01 \n", line[i]))
		{
			if (ft_strchr("NWSE", line[i]))
			{
				if (!(data->player_direction))
					data->player_direction = line[i];
				else
				{
					perror("more than 1 player\n");
					return (0);
				}
			}
			else
			{
				perror("error\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	map_getinfo(int fd, t_info *data)
{
	char	*l;
	int		flag;

	flag = 0;

	while(get_next_line(fd, &l))
	{
		if (ft_strlen(l) > (size_t)data->width)
			data->width = ft_strlen(l);
		if (!map_character_checking(l, data))
			return (0);
		free(l);
		data->height++;
	}
	free(l);
	return (1);
}

int	map_parsing(char *file, t_info *data)
{
	int	fd;
	if (map_filetype(file) < 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (!map_getinfo(fd, data))
	{	
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

char	*map_padding(char *line, int size)
{
	char	*ret;

	while (size > 0)
	{
		ret = ft_strjoin(line, " ");
		size--;
		free(line);
		line = ret;
	}
	return (ret);
}
void	map_initialize(char *file, t_info *data)
{
	int		fd;
	char	*l;
	int		i;

	i = 0;
	data->map = ft_calloc(sizeof(char *), data->height);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &l))
	{
		if (ft_strlen(l) < (size_t)data->width)
			data->map[i] = ft_strdup(map_padding(l, data->width - ft_strlen(l)));
		else
		{
			data->map[i] = ft_strdup(l);
			free(l);
		}
		i++;
	}
	data->map[i] = NULL;
 	close(fd);
}

void	printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

