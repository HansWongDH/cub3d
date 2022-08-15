/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/15 15:33:56 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);

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

int	map_character_checking(t_map *map, char *line, t_coord *player_pos, int *player_direction)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (!ft_strchr("01 \n", line[i]))
		{
			if (ft_strchr("NWSE", line[i]))
			{
				if (!(*player_direction))
				{
					*player_direction = line[i];
					player_pos->x = i;
					player_pos->y = map->row;
				}
				else
				{
					ft_putstr_fd("More than 1 Player\n", 2);
					return (0);
				}
			}
			else
			{
				ft_putstr_fd("Invalid Character Found In Map\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	map_getinfo(t_map *map, int fd, t_coord *player_pos, int *player_direction)
{
	char	*line;

	while(get_next_line(fd, &line))
	{
		if (ft_strlen(line) > (size_t)map->col)
			map->col = ft_strlen(line);
		if (!map_character_checking(map, line, player_pos, player_direction))
			return (0);
		free(line);
		map->row++;
	}
	free(line);
	if (!player_direction)
		return (0);
	return (1);
}

int	map_parsing(t_map *map, char *file, t_coord *player_pos, int *player_direction)
{
	int	fd;

	map->col = 0;
	map->row = 0;
	if (map_filetype(file) < 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (!map_getinfo(map, fd, player_pos, player_direction))
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

void	map_create(t_map *map, char *file, t_coord *player_pos)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->array = ft_calloc(sizeof(char *), map->row);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) < (size_t)map->col)
			map->array[i] = ft_strdup(map_padding(line, map->col - ft_strlen(line)));
		else
		{
			map->array[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
	map->array[i] = NULL;
	map->array[player_pos->y][player_pos->x] = '0';
	close(fd);
}
