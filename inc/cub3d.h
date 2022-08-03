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
# define KEY_Q		12
# define KEY_E		14

# define ROW		11
# define COL		15
# define TILE_SIZE	32
# define WIDTH		COL * TILE_SIZE
# define HEIGHT		ROW * TILE_SIZE
# define MOVE_GAP	3


# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define GRAY		0x808080
# define PINK		0xFF00FF
# define PI			3.1415926

typedef struct	s_vec {
	double		x;
	double		y;
	// double		a;
	// double		dx;
	// double		dy;
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
	t_vec		player_pos;
	t_vec		fov;
	double		player_direction;
	t_img		img;
}				t_data;
