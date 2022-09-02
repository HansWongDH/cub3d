/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:14:39 by wding-ha          #+#    #+#             */
/*   Updated: 2022/09/02 17:10:18 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//might have to check for invalid amount of commas in while loop idk
static	int	strict_order(t_map *map, char *s, int i, char *line)
{
	const char	*arr[7] = {"NO", "SO", "WE", "EA", "DO", "F", "C"};

	if (!ft_strcmp(s, arr[i]))
		return (1);
	free(line);
	return (set_map_flag(map, MAP_WRONG_ELEM_ORDER));
}

static unsigned int	check_colour(t_data *data, t_map *map, char *s, char *line)
{
	int		colour;
	char	**args;
	int		i;

	i = 0;
	if (!check_argument(line, 1, 0))
		return (set_map_flag(map, MAP_INVALID_RBG));
	while (line[++i])
	{
		if (line[i] == ',')
			line[i] = ' ';
	}
	args = ft_split(line, ' ');
	colour = create_rgb(args);
	if (colour < 0)
	{
		free(line);
		return (set_map_flag(map, MAP_INVALID_RBG));
	}
	if (!ft_strcmp(s, "F"))
		data->floor = colour;
	else
		data->ceiling = colour;
	return (1);
}

static int	check_path(char *s)
{
	int	fd;

	if (!s)
		return (0);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	fetch_element(t_data *data, t_map *map, char **args, char *line)
{
	if (!ft_strcmp(args[0], "NO") && check_path(args[1]))
		data->north_wall.path = ft_strdup(args[1]);
	else if (!ft_strcmp(args[0], "SO") && check_path(args[1]))
		data->south_wall.path = ft_strdup(args[1]);
	else if (!ft_strcmp(args[0], "EA") && check_path(args[1]))
		data->east_wall.path = ft_strdup(args[1]);
	else if (!ft_strcmp(args[0], "WE") && check_path(args[1]))
		data->west_wall.path = ft_strdup(args[1]);
	else if (!ft_strcmp(args[0], "DO") && check_path(args[1]))
		data->door.path = ft_strdup(args[1]);
	else if (!ft_strcmp(args[0], "F") || !ft_strcmp(args[0], "C"))
		return (check_colour(data, map, args[0], line));
	else
	{
		free(line);
		return (set_map_flag(map, MAP_MISSING_ELEM));
	}
	return (1);
}

int	parse_element(t_data *data, t_map *map, int fd)
{
	char		*line;
	char		**args;
	int			i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		args = ft_split(line, ' ');
		if (args[0])
		{
			if (!strict_order(map, args[0], i, line))
				return (free_2d(args));
			if (!fetch_element(data, map, args, line))
				return (free_2d(args));
			i++;
		}
		free_2d(args);
		free(line);
		data->index++;
		if (i == 7)
			break ;
	}
	if (i != 7)
		return (set_map_flag(map, MAP_MISSING_ELEM));
	return (1);
}
