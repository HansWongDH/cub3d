#ifndef	PLAYER_CLASS_H
# define PLAYER_CLASS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# include "structs.h"

typedef struct	c_player	t_player;

typedef void		(*t_move_player)(t_player *self, int keycode);
typedef void		(*t_turn_player)(t_player *self, int keycode);
typedef void		(*t_print_player)(t_player *self);

struct			c_player
{
	t_move_player	move_player;
	t_turn_player	turn_player;
	t_print_player	print_player;
	t_vec			pos;
	t_vec			ray_dir;
	float			direction;
	int				size;
};

t_player	player_init(void);
void		move_player(t_player *self, int keycode);
void		turn_player(t_player *self, int keycode);
void		print_player(t_player *self);
#endif
