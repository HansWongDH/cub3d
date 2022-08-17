#ifndef	STRUCTS_H
# define STRUCTS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_img
{
	void		*img_p;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_xpm
{
	void		*img_p;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_xpm;

typedef struct	s_math
{
	double		camera_x;
	t_vec		ray_dir;
	t_vec		delta_dist;
	t_vec		side_dist;
	t_coord		map_pos;
	t_coord		step;
}				t_math;

#endif
