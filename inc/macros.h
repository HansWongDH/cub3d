/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:49:35 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 16:44:11 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_KEY_EXIT		17
# define X_MOUSE_MOVE	6

# define WINDOW_WIDTH	1200 //1200 1440
# define WINDOW_HEIGHT	900 //900 1056

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S  		1
# define KEY_D  		2
# define KEY_Q			12
# define KEY_E			14
# define KEY_U_ARROW	126
# define KEY_R_ARROW	124
# define KEY_D_ARROW	125
# define KEY_L_ARROW	123
# define KEY_SPACE		49

# define MOVE_GAP			3
# define PLAYER_SIZE		10
# define ROTATE_FACTOR		27
# define SENSITIVITY		1.0
# define MAP_TRANSPARENCY	75

# define TILE_SIZE			16
# define DISPLAY_ROW		15
# define DISPLAY_COL		15

# define GAME_SCALE			16
# define Y_SCALE			375

# define GUN_WIDTH			128
# define GUN_HEIGHT			128
# define GUN_X_SCALE		3
# define GUN_Y_SCALE		3

# define HUD_Y_SCALE		2

# define XPM_SIZE			64

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

# define FLOORCOL		0x1E1E18 //0x1E1E18 30,30,24 || 28,28,27
# define CIELCOL		0x183C30 //0x183C30 24,60,48 || 2,75,110
# define DOOR_CL_COL	0xffba08
# define DOOR_OP_COL	0x4daa57
# define WALLCOL		GRAY

# define PR_RESET	"\x1B[0m"
# define PR_RED		"\x1B[31m"
# define PR_GREEN	"\x1B[32m"
# define PR_YELLOW	"\x1B[33m"
# define PR_BLUE	"\x1B[34m"
# define PR_MAGENTA	"\x1B[35m"
# define PR_CYAN	"\x1B[36m"
# define PR_WHITE	"\x1B[37m"

#endif
