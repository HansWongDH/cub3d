#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

#include "macros.h"

unsigned int	get_argb_val(int colour, int transparency);
int				is_movement_keys(int keycode);
int				shade_colour(int colour, int percent);

#endif
