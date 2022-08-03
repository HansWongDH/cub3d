# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S  	1
# define KEY_D  	2

# define ROW		11
# define COL		15
# define TILE_SIZE	32
# define WIDTH		COL * TILE_SIZE
# define HEIGHT		ROW * TILE_SIZE

typedef struct	s_vec {
	double		x;
	double		y;
}				t_vec;

typedef struct	s_img {
	void		*img;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	int			map[ROW][COL];
	t_img		img;
}				t_data;
