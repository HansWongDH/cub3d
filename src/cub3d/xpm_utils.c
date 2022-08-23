/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:01:43 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/23 15:08:32 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	init_xpm(void *mlx, t_xpm *xpm, char *path_to_xpm)
{
	xpm->img_p = mlx_xpm_file_to_image(mlx, path_to_xpm, &xpm->width,
			&xpm->height);
	xpm->data = (int *)mlx_get_data_addr(xpm->img_p,
			&xpm->bpp, &xpm->line_size, &xpm->endian);
}
