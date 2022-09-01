/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:10:30 by wding-ha          #+#    #+#             */
/*   Updated: 2022/09/01 14:19:39 by wding-ha         ###   ########.fr       */
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

void	print_map_error(t_error_id err)
{
	const char	*err_arr[] = {"MAP HAS TOO MANY PLAYERS\n",
		"MAP HAS AN INVALID CHAR\n", "MAP HAS NO PLAYER\n",
		"MAP HAS WRONG FILE EXTENSION\n", "MAP WAS AN INVALID FILE\n",
		"MAP WAS NOT ENCLOSED\n", "MAP MISSING ELEMENT\n",
		"MAP INVALID RGB\n"};

	ft_putstr_fd(PR_RED, 2);
	ft_putstr_fd((char *)err_arr[err - 2], 2);
	ft_putstr_fd(PR_RESET, 2);
}

int	map_filetype(t_map *map, char *file)
{
	char	*file_type;

	if (ft_strlen(file) < 5)
		return (set_map_flag(map, MAP_INVALID_FILE));
	file_type = ft_substr(file, ft_strlen(file) - 4, 4);
	if (ft_strcmp(file_type, ".cub"))
	{
		free(file_type);
		return (set_map_flag(map, MAP_WRONG_FILE_EXT));
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

int	set_map_flag(t_map *map, t_error_id err)
{
	map->flag = err;
	printf("map->err_id = %d\n", err);
	return (0);
}
