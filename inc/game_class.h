#ifndef	GAME_CLASS_H
# define GAME_CLASS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# include "map_class.h"
# include "macros.h"
# include "structs.h"
# include "cub3d.h"

typedef struct	c_game		t_game;
typedef struct	s_data		t_data;

typedef void	(*t_draw_sky)(t_game *self);
typedef	void	(*t_draw_game)(t_data *data);

struct		c_game
{
	t_draw_sky	draw_sky;
	t_draw_game	draw_game;
	t_img		img;
	int			height;
	int			width;
};

t_game	game_init(t_map *map, void *mlx);
void	draw_game(t_data *data);
void	draw_sky(t_game *self);

#endif
