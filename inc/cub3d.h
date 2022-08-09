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

# define ROW			11
# define COL			15
# define TILE_SIZE		32
# define WIDTH			COL * TILE_SIZE //480
# define HEIGHT			ROW * TILE_SIZE //352
# define MOVE_GAP		3
# define PLAYER_SIZE	10

# define GAME_SCALE		16
# define GAME_TILE		GAME_SCALE * TILE_SIZE //256
# define GAME_WIDTH 	WIDTH * 3
# define GAME_HEIGHT	HEIGHT * 3

# define XPM_SIZE		64

# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GRAY			0x808080
# define PINK			0xFF00FF
# define YELLOW			0xFFFF00
# define LBLUE			0x00B4D8
# define BROWN			0xAB3428
# define PI				3.141592653589793238

typedef struct	s_vec {
	float		x;
	float		y;
}				t_vec;

typedef struct	s_img {
	void		*img;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_xpm {
	void		*img;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_xpm;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	int			map[ROW][COL];
	t_vec		player_pos;
	t_vec		fov;
	float		player_direction;
	t_img		img;
	t_xpm		wall;
	t_img		game;
}				t_data;
