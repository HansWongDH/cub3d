#ifndef MACROS_H
# define MACROS_H

# define PI				3.14159265359

# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_KEY_EXIT		17
# define X_MOUSE_MOVE	6

# define WINDOW_WIDTH	1440 //1200
# define WINDOW_HEIGHT	1056 //900

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S  	1
# define KEY_D  	2
# define KEY_Q		12
# define KEY_E		14

# define MOVE_GAP			3
# define PLAYER_SIZE		10
# define ROTATE_FACTOR		PI / 54
# define MAP_TRANSPARENCY	75

# define ROW				11 //remove to be dynamic
# define COL				15 //remove to be dynamic
# define TILE_SIZE			32
# define WIDTH				COL * TILE_SIZE //480 //remove to be dynamic
# define HEIGHT				ROW * TILE_SIZE //352 //remove to be dynamic

# define GAME_SCALE			16
# define GAME_TILE			GAME_SCALE * TILE_SIZE //256
# define GAME_WIDTH 		WIDTH * 3 //needs to by dynamic
# define GAME_HEIGHT		HEIGHT * 3 //needs to by dynamic
# define X_SCALE			4
# define Y_INV_SCALE		32000
# define Y_SCALE(distance)	(28000/distance)

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

# define WALLCOL		GRAY

#endif
