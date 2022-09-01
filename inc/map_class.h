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
	int						player_direction;
	t_coord					player_pos;
	int						flag;
};

t_map   map_init(t_data *data, char *file);
void	print_map(t_map *self);
void	draw_map(t_map *self, t_player *player);

void	draw_display_map(t_map *map, t_player *player);
void	draw_display_border(t_map *map);
void	draw_display_player(t_map *map, t_player *player);
void	draw_display_player_direction(t_map *map, t_player *player);
void	draw_square(int *img_data, t_coord tile_coord, int width, int colour);
void	draw_tiles(t_map *map);

void	map_create(t_map *map, char *file, int index);
int		map_parsing(t_map *map, t_data *data, char *file);
int		map_validation(t_map *map);
void	map_skip_element(int fd, int index);

int		parse_element(int fd, t_data *data);
int		free_2d(char **s);
void	print_map_error(t_error_id err);
int		set_map_flag(t_map *map, t_error_id err);
int		map_filetype(t_map *map, char *file);
#endif
