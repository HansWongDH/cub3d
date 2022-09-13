/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:48:10 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 10:48:30 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "macros.h"

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

unsigned int	get_argb_val(int colour, int transparency);
int				is_movement_keys(int keycode);
int				shade_colour(int colour, int percent);

#endif
