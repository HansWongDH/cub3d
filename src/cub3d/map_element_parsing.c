/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:14:39 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/24 20:26:38 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(char **s)
{
	int	i;
	i = 0;
	
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int		create_rgb(int *colour)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colour[i] > 255 || colour[i] < 0)
			return (-1);
		i++;
	}
	return (colour[0] << 16 | colour[1] << 8 | colour[2]);
}

int	check_colour(char *s, t_data *data)
{
	char			**args;
	int				i;
	int				colour[3];

	args = ft_split(s, ',');
	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
	if (i != 3)
	{
		free_2d(args);
		return (0);
	}
	i = -1;
	while (++i < 3)
		colour[i] = ft_atoi(args[i]);
	free_2d(args);
	if (create_rgb(colour) < 0)
		return (0);
	if (!ft_strcmp(s, "F") && data->floor < 0)
		data->floor = create_rgb(colour);
	else
		data->ceiling = create_rgb(colour);
	printf("OAIJOIFAIOAC %x\n", data->floor);
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

int	fetch_element(char	**args, t_data *data)
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
		return (check_colour(args[1], data));
	else
		return (0);
	return (1);
}

int	parse_element(int fd, t_data *data)
{
	char		*line;
	int			ret;
	char		**args;
	int			i;

	ret = get_next_line(fd, &line);
	if (ret < 0)
		return(0);
	i = 0;
	data->index = 0;
	while (ret > 0)
	{
		args = ft_split(line, ' ');
		if (args[0])
		{
			if (!fetch_element(args, data))
				return (0);
			if (args[2])
				return (0);
			i++;
			free_2d(args);
		}
		if (line)
			free(line);
		data->index++;
		if (i == 6)
			break ;
		ret = get_next_line(fd, &line);
	}
	return (1);
}