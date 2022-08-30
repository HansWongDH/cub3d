/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:14:39 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/30 15:18:40 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(char **args)
{
	int	i;
	int	colour[3];

	i = 0;
	while (args[i])
		i++;
	if (i != 4)
	{
		free_2d(args);
		return (-1);
	}
	i = -1;
	while (++i < 3)
		colour[i] = ft_atoi(args[i + 1]);
	free_2d(args);
	i = 0;
	while (i < 3)
	{
		if (colour[i] > 255 || colour[i] < 0)
			return (-1);
		i++;
	}
	return (0 << 24 | colour[0] << 16 | colour[1] << 8 | colour[2]);
}

unsigned int	check_colour(char*s, char *line, t_data *data)
{
	char	**args;
	int		i;
	int		colour;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			line[i] = ' ';
		i++;
	}
	args = ft_split(line, ' ');
	colour = create_rgb(args);
	if (colour < 0)
		return (0);
	if (!ft_strcmp(s, "F") && data->floor < 0)
		data->floor = colour;
	else if (data->ceiling < 0)
		data->ceiling = colour;
	else
		return (0);
	return (1);
}

int	check_path(char *s)
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

int	fetch_element(char	**args, t_data *data, char *line)
{
	if (!ft_strcmp(args[0], "NO") && check_path(args[1]))
	{	
		if (!data->north_wall.path)
			data->north_wall.path = ft_strdup(args[1]);
	}
	else if (!ft_strcmp(args[0], "SO") && check_path(args[1]))
	{	
		if (!data->south_wall.path)
			data->south_wall.path = ft_strdup(args[1]);
	}
	else if (!ft_strcmp(args[0], "EA") && check_path(args[1]))
	{	
		if (!data->east_wall.path)
			data->east_wall.path = ft_strdup(args[1]);
	}
	else if (!ft_strcmp(args[0], "WE") && check_path(args[1]))
	{	
		if (!data->west_wall.path)
			data->west_wall.path = ft_strdup(args[1]);
	}
	else if (!ft_strcmp(args[0], "F") || !ft_strcmp(args[0], "C"))
		return (check_colour(args[0], line, data));
	else
		return (0);
	return (1);
}

int	parse_element(int fd, t_data *data)
{
	char		*line;
	char		**args;
	int			i;

	if (get_next_line(fd, &line) < 0)
		return (0);
	i = 0;
	while (1)
	{
		args = ft_split(line, ' ');
		if (args[0])
		{
			if (!fetch_element(args, data, line))
				return (free_2d(args));
			i++;
		}
		free_2d(args);
		free(line);
		data->index++;
		if (i == 6)
			break ;
		get_next_line(fd, &line);
	}
	return (1);
}
