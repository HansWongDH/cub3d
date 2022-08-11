# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# define PI				3.14159265359

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

# define MOVE_GAP		3
# define PLAYER_SIZE	10
# define ROTATE_FACTOR	PI / 72

# define ROW			11 //remove to be dynamic
# define COL			15 //remove to be dynamic
# define TILE_SIZE		32
# define WIDTH			COL * TILE_SIZE //480 //remove to be dynamic
# define HEIGHT			ROW * TILE_SIZE //352 //remove to be dynamic

# define GAME_SCALE		16
# define GAME_TILE		GAME_SCALE * TILE_SIZE //256
# define GAME_WIDTH 	WIDTH * 3
# define GAME_HEIGHT	HEIGHT * 3
# define X_SCALE		4
# define Y_INV_SCALE	32000

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
# define FLOORCOL		0x1E1E18
# define CIELCOL		0x183C30

typedef struct	c_player	t_player;
typedef struct	c_map		t_map;

typedef enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_direction;

typedef struct	s_vec
{
	float		x;
	float		y;
}				t_vec;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_img
{
	void		*pointer;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_xpm
{
	void		*img;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_xpm;

struct			c_player
{
	void		(*move_player)(t_player *self, int keycode);
	void		(*turn_player)(t_player *self, int keycode);
	void		(*print_player)(t_player *self);
	t_vec		pos;
	t_vec		ray_dir;
	float		player_direction;
};

typedef	void	(*t_print_map)(t_map *self);
typedef void	(*t_draw_map)(t_map *self, t_player *player);

struct			c_map
{
	void		(*draw_map)(t_map *self, t_player *player);
	t_print_map	print_map;
	t_draw_map	img;
	int			array[ROW][COL];
	int			col;
	int			row;
	int			height;
	int			width;
};

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			map[ROW][COL];
	t_vec		player_pos;
	t_vec		fov;
	float		player_direction;
	t_img		img;
	t_xpm		north_wall;
	t_xpm		east_wall;
	t_xpm		south_wall;
	t_xpm		west_wall;
	t_img		game;
	t_map		test_map;
	t_player	test_player;
}				t_data;

float			get_positive_value_of_angle(float angle);
t_player		player_init(void);
