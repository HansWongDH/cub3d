#ifndef	MAP_CLASS_H
# define MAP_CLASS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# include "player_class.h"
# include "structs.h"
# include "macros.h"

typedef struct	c_map		t_map;
typedef struct	c_player	t_player;
typedef struct	s_data		t_data;

typedef	void	(*t_print_map)(t_map *self);
typedef void	(*t_draw_map)(t_map *self, t_player *player);

struct			c_map
{
	t_draw_map				draw_map;
	t_print_map				print_map;
	t_img					img;
	t_img					display;
	char					**array;
	int						col;
	int						row;
	int						height;
	int						width;
	int						display_height;
	int						display_width;
	int						flag;
};

t_map   map_init(t_data *data, char *file, t_coord *player_pos, int *player_direction);
void	print_map(t_map *self);
void	draw_map(t_map *self, t_player *player);

void	draw_display_map(t_map *map, t_player *player);
void	draw_square(int *img_data, t_coord tile_coord, int width, int colour);
void	draw_tiles(t_map *map);
void	draw_player(t_map *map, t_player *player);
void	draw_display_border(t_map *map);
void	draw_display_player(t_map *map, t_player *player);
void	draw_display_player_direction(t_map *map, t_player *player);
#endif
