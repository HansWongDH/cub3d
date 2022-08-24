#ifndef	CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "map_class.h"
# include "player_class.h"
# include "macros.h"
# include "structs.h"
# include "game_class.h"
# include "libft.h"
# include "utils.h"

typedef enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_direction;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	//int			map[ROW][COL];
	//t_vec		player_pos;
	//t_vec		fov;
	//float		player_direction;
	//t_img		img;
	//t_img		game;
	t_xpm		north_wall;
	t_xpm		east_wall;
	t_xpm		south_wall;
	t_xpm		west_wall;
	t_xpm		door;
	t_game		game;
	t_map		map;
	t_player	player;
	t_coord		mouse_pos;
}				t_data;

float			get_positive_value_of_angle(double angle);
int				handle_key(int keycode, t_data *data);
int				handle_exit(int keycode, t_data *data);
int				handle_mouse(int x, int y, t_data *data);
void			init_images(t_data *data);
void			init_data(t_data *data, char *file);
void			printmap(char **map);
void			map_create(t_map *map, char *file, t_coord *player_pos);
int				map_parsing(t_map *map, char *file, t_coord *player_pos, int *player_direction);
int				map_validation(t_map *map);
//unsigned int	get_argb_val(int colour, int transparency);
int				shade_colour(int colour, int percent);
void			init_xpm(void *mlx, t_xpm *xpm, char *path_to_xpm);
t_vec			add_vectors(t_vec v1, t_vec v2);
t_vec			subtract_vectors(t_vec v1, t_vec v2);
t_vec			equate_vectores(t_vec v1);

#endif
