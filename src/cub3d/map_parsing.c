/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/30 15:58:46 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	map_character_checking(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01 D\n", line[i]))
		{
			if (ft_strchr("NWSE", line[i]))
			{
				if (!(map->player_direction))
				{
					map->player_direction = line[i];
					map->player_pos.x = i;
					map->player_pos.y = map->row;
				}
				else
					return (print_error("More than 1 Player\n", 2));
			}
			else
				return (print_error("Invalid Character Found In Map\n", 2));
		}
		i++;
	}
	return (1);
}

int	map_getinfo(t_map *map, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > (size_t)map->col)
			map->col = ft_strlen(line);
		if (!map_character_checking(map, line))
			return (0);
		free(line);
		map->row++;
	}
	printf("map row is %d\n", map->row);
	free(line);
	if (!map->player_direction)
		return (0);
	return (1);
}

int	map_parsing(t_map *map, t_data *data, char *file)
{
	int	fd;

	map->col = 0;
	map->row = 0;
	if (map_filetype(file) < 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (!parse_element(fd, data))
	{
		close(fd);
		return (0);
	}
	if (!map_getinfo(map, fd))
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

void	map_create(t_map *map, char *file, int index)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->array = ft_calloc(sizeof(char *), map->row);
	fd = open(file, O_RDONLY);
	map_skip_element(fd, index);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) < (size_t)map->col)
			map->array[i] = map_padding(line, map->col - ft_strlen(line));
		else
		{
			map->array[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
	map->array[i] = NULL;
	map->array[map->player_pos.y][map->player_pos.x] = '0';
	close(fd);
	free(line);
}
