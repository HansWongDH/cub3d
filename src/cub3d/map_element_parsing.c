/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:14:39 by wding-ha          #+#    #+#             */
/*   Updated: 2022/08/24 16:10:22 by wding-ha         ###   ########.fr       */
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

int		create_rgb(int r, int g, int b, unsigned int *color)
{
	if ((r || g || b) > 255 || (r || g || b) < 0)
		return (0);
	color = r << 16 | g << 8 | b;
}

int	check_colour(char *s, t_data *data)
{
	char			**args;
	int				i;
	int				colour[3];
	unsigned int	colourcode;

	args = ft_split(s, ',');
	i = 0;
	while (args[i])
		i++;
	if (i != 3)
	{
		free_2d(args);
		return (0);
	}
	i = -1;
	while (++i < 3)
		colour[i] = ft_atoi(args[i]);
	free_2d(args);
	if (!create_rgb(colour[0], colour[1], colour[2], colourcode))
		return (0);
	if (!ft_strcmp(s, "F") && data->floor < 0)
		data->floor = colourcode;
	else
		data->ceiling = colourcode;
}
		
int	check_path(char *s)
{
	int	ret;

	if (!s)
		return (0);
	ret = open(s, O_RDONLY);
	if (ret < 0)
		return (0);
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
	else if (!ft_strcmp(args[0], "F") || !ft_strcmp(args[0], "F"))
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

	ret = get_next_line(fd, &line);
	if (ret < 0)
		return(0);
	while (ret >= 0)
	{
		if (ret != 0)
		{
			args = ft_split(line, ' ');
			if (!fetch_element(args, data))
				return (0);
			free_2d(args);
		}
		free(line);
		ret = get_next_line(fd, &line);
	}
	return (1);
}