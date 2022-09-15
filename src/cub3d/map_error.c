/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:35:15 by wding-ha          #+#    #+#             */
/*   Updated: 2022/09/13 14:48:59 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_class.h"
#include "libft.h"

int	set_map_flag(t_map *map, t_error_id err)
{
	map->flag = err;
	printf("map->err_id = %d\n", err);
	return (0);
}

void	print_map_error(t_error_id err)
{
	const char	*err_arr[] = {"MAP HAS TOO MANY PLAYERS\n",
		"MAP HAS AN INVALID CHAR\n", "MAP HAS NO PLAYER\n",
		"MAP HAS WRONG FILE EXTENSION\n", "MAP WAS AN INVALID FILE\n",
		"MAP WAS NOT ENCLOSED\n", "MAP MISSING ELEMENT\n",
		"MAP INVALID RGB\n", "MAP WRONG ELEMENT ORDER\n",
		"MAP INVALID PATH\n"};

	ft_putstr_fd(PR_RED, 2);
	ft_putstr_fd((char *)err_arr[err - 2], 2);
	ft_putstr_fd(PR_RESET, 2);
}
