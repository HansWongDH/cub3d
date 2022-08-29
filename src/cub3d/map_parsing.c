/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:09:33 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/29 19:51:02 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

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

int	map_character_checking(t_map *map, char *line, t_coord *player_pos, int *pd)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01 D\n", line[i]))
		{
			if (ft_strchr("NWSE", line[i]))
			{
				if (!(*pd))
				{
					*pd = line[i];
					player_pos->x = i;
					player_pos->y = map->row;
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

int	map_getinfo(t_map *map, int fd, t_coord *player_pos, int *pd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > (size_t)map->col)
			map->col = ft_strlen(line);
		if (!map_character_checking(map, line, player_pos, pd))
			return (0);
		free(line);
		map->row++;
	}
	printf("map row is %d\n", map->row);
	free(line);
	if (!pd)
		return (0);
	return (1);
}

int	map_parsing(t_map *map, t_data *data, char *file, t_coord *player_pos, int *pd)
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
	if (!map_getinfo(map, fd, player_pos, pd))
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

void	map_create(t_map *map, char *file, t_coord *player_pos, int index)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->array = ft_calloc(sizeof(char *), map->row);
	fd = open(file, O_RDONLY);
	while (index > 0)
	{
		get_next_line(fd, &line);
		free(line);
		index--;
	}
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
	map->array[player_pos->y][player_pos->x] = '0';
	close(fd);
	free(line);
}
