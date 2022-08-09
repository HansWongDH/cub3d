#include "cub3d.h"
#include "libft.h"

//int shade_colour(char *colour, float percent)
//{
//	(void)percent;
//	printf("R = %s\n", ft_substr(colour, 2, 2));
//	printf("G = %s\n", ft_substr(colour, 4, 2));
//	printf("B = %s\n", ft_substr(colour, 6, 2));
//	
//	printf("R = %d\n", (int)strtol(ft_substr(colour, 2, 2), NULL, 16) * (int)(100 + percent)/100);
//	printf("G = %d\n", (int)strtol(ft_substr(colour, 4, 2), NULL, 16) * (int)(100 + percent)/100);
//	printf("B = %d\n", (int)strtol(ft_substr(colour, 6, 2), NULL, 16) * (int)(100 + percent)/100);
//
//	int	temp_R = (int)strtol(ft_substr(colour, 2, 2), NULL, 16) * (int)(100 + percent)/100;
//	int	temp_G = (int)strtol(ft_substr(colour, 4, 2), NULL, 16) * (int)(100 + percent)/100;
//	int	temp_B = (int)strtol(ft_substr(colour, 6, 2), NULL, 16) * (int)(100 + percent)/100;
//
//	int R = temp_R < 255 ? temp_R : 255;
//	int G = temp_G < 255 ? temp_G : 255;
//	int B = temp_B < 255 ? temp_B : 255;
//
//	printf("%d%d%d\n", R,G,B);
//
//	// printf("%s\n", );
//	// int	RR = (int)strtol(ft_substr(colour, 2, 2), NULL, 16);
//	// int	temp_G = (int)strtol(ft_substr(colour, 4, 2), NULL, 16);
//	// int	temp_B = (int)strtol(ft_substr(colour, 6, 2), NULL, 16);
//
//	// printf("%s\n", );
//
//	return (0);
//}

int shade_colour(int colour, int percent)
{
	(void)percent;
	//printf("R = %s\n", ft_substr(colour, 2, 2));
	//printf("G = %s\n", ft_substr(colour, 4, 2));
	//printf("B = %s\n", ft_substr(colour, 6, 2));

	//int    temp_R = (int)strtol(ft_substr(colour, 2, 2), NULL, 16);
	//int    temp_G = (int)strtol(ft_substr(colour, 4, 2), NULL, 16);
	//int    temp_B = (int)strtol(ft_substr(colour, 6, 2), NULL, 16);

	//int    temp_R = (int)strtol(ft_substr(colour, 2, 2), NULL, 16) * (int)(100 + percent)/100;
	//int    temp_G = (int)strtol(ft_substr(colour, 4, 2), NULL, 16) * (int)(100 + percent)/100;
	//int    temp_B = (int)strtol(ft_substr(colour, 6, 2), NULL, 16) * (int)(100 + percent)/100;

	//printf("R = %d\n", temp_R);
	//printf("G = %d\n", temp_G);
	//printf("B = %d\n", temp_B);

	//int R = temp_R < 255 ? temp_R : 255;
	//int G = temp_G < 255 ? temp_G : 255;
	//int B = temp_B < 255 ? temp_B : 255;

	//printf("%d%d%d\n", R,G,B);

	//int    test = B * 65536 + G * 256 + R;
	//printf("%ld\n", test);

	//int    RR = (int)strtol(ft_substr(colour, 2, 2), NULL, 16);
	//int    temp_G = (int)strtol(ft_substr(colour, 4, 2), NULL, 16);
	//int    temp_B = (int)strtol(ft_substr(colour, 6, 2), NULL, 16);

	//colour = (colour & 0xfefefe) >> 1;
	int i = 0;
	while (i++ < percent)
		colour = ((colour & 0x7E7E7E) >> 1) | (colour & 0x808080);

	//int test = (((colour & 0x0000FF) + percent) | ((((colour >> 8) & 0x00FF) + percent) << 8) | (((colour >> 16) + percent) << 16));
	//colour = ((colour & 0x7E7E7E) >> 1) | (colour & 0x808080);
	//printf("col = %ld\n", test);
	return (colour);
}

int	handle_key(int keycode, t_data *data)
{
	(void)data;
	int	valid;
	float	to_move_x;
	float	to_move_y;

	valid = 1;
	//if (keycode == KEY_Q)
	//{
	//	data->player_direction -= 0.13;
	//	if (data->player_direction < 0)
	//		data->player_direction += 2 * PI;
	//	data->fov.x = cos(data->player_direction);
	//	data->fov.y = sin(data->player_direction);
	//}
	//if (keycode == KEY_E)
	//{
	//	data->player_direction += 0.13;
	//	if (data->player_direction > 2 * PI)
	//		data->player_direction += 2 * PI;
	//	data->fov.x = cos(data->player_direction);
	//	data->fov.y = sin(data->player_direction);
	//}
	if (keycode == KEY_W)
	{
		printf("================\n");
		printf("fov_x = %f\n", data->fov.x);
		printf("fov_y = %f\n", data->fov.y);

		to_move_x = ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.x + data->player_pos.x);
		to_move_y = ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.y + data->player_pos.y);

		printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
		printf("to_move_x = %f\n", to_move_x);
		printf("to_move_y = %f\n", to_move_y);
		//for (int i = 0; i < 5; i++)
		//{
		if (data->img.data[(WIDTH * (int)to_move_y + (int)to_move_y)] == GREEN)
		{
			printf("WALL\n");
			return 0;
		}
		//}
		data->player_pos.x += data->fov.x * MOVE_GAP;
		data->player_pos.y += data->fov.y * MOVE_GAP;
		printf("================\n");
	}
	if (keycode == KEY_A)
	{
		//if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x - MOVE_GAP - 5)] != GREEN)
		//	data->player_pos.x -= MOVE_GAP;
		data->player_direction -= PI/72;
		if (data->player_direction < 0)
			data->player_direction += 2 * PI;
		data->fov.x = cos(data->player_direction);
		data->fov.y = sin(data->player_direction);
	}
	if (keycode == KEY_S)
	{
		//if (data->img.data[(WIDTH * ((int)data->player_pos.y + MOVE_GAP + 5)) + (int)data->player_pos.x] != GREEN)
		//	data->player_pos.y += MOVE_GAP;

		//data->player_pos.x -= (data->fov.x * MOVE_GAP);
		//data->player_pos.y -= (data->fov.y * MOVE_GAP);

		printf("================\n");
		printf("fov_x = %f\n", data->fov.x);
		printf("fov_y = %f\n", data->fov.y);

		to_move_x = data->player_pos.x - ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.x);
		to_move_y = data->player_pos.y - ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.y);

		printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
		printf("to_move_x = %f\n", to_move_x);
		printf("to_move_y = %f\n", to_move_y);
		//for (int i = 0; i < 5; i++)
		//{
		if (data->img.data[(WIDTH * (int)to_move_y + (int)to_move_y)] == GREEN)
		{
			printf("WALL\n");
			return 0;
		}
		//}
		data->player_pos.x -= data->fov.x * MOVE_GAP;
		data->player_pos.y -= data->fov.y * MOVE_GAP;
		printf("================\n");
	}
	if (keycode == KEY_D)
	{
		//if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x + MOVE_GAP + 5)] != GREEN)
		//	data->player_pos.x += MOVE_GAP;
		data->player_direction += PI/72;
		if (data->player_direction > 2 * PI)
			data->player_direction -= 2 * PI;
		data->fov.x = cos(data->player_direction);
		data->fov.y = sin(data->player_direction);
	}
	if (keycode == KEY_ESC)
		exit(0);
	printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
	printf("Player direction = %f\n", data->player_direction);
	return (0);
}

int	handle_exit(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
}

void	draw_square(t_data *data, int i, int j, int colour)
{
	int	x;
	int	y;

	x = 0;
	while (x < TILE_SIZE)
	{
		y = 0;
		while (y < TILE_SIZE)
		{
			data->img.data[WIDTH * (x + i) + (y + j)] = colour;
			y++;
		}
		x++;
	}
}

void	draw_grid(t_data *data, int i, int j, int colour)
{
	int	x;
	int	y;

	x = 0;
	while (x < TILE_SIZE)
	{
		y = 0;
		if (x == 0 || x == TILE_SIZE)
		{
			while (y < TILE_SIZE)
			{
				data->img.data[WIDTH * (i) + (y + j)] = colour;
				y++;
			}
		}
		else
			data->img.data[WIDTH * (i + x) + (j)] = colour;
		x++;
	}
}

void	draw_tiles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COL)
		{
			if (data->map[i][j] == 1)
			{
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, GREEN);
				//draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, GRAY);
			}
			else
			{
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, WHITE);
				//draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, BLACK);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	player_size;

	player_size = 10;
	i = 0;
	while (i < player_size)
	{
		j = 0;
		while (j < player_size)
		{
			data->img.data[WIDTH * ((int)data->player_pos.y + j - (player_size / 2)) +
				((int)data->player_pos.x + i - (player_size / 2))] = PINK;
			j++;
		}
		i++;
	}
}

void	draw_game(t_data *data, float x, float y, float angle)
{
	float	distance;
	// float	angle_offset;
	// data->img.data[WIDTH * ((int)y) + ((int)x)] = BLUE;


	//printf("x,y | %f %f\n", x, y);
	distance = sqrt(pow(data->player_pos.x - x, 2) + pow(data->player_pos.y - y, 2));
	//printf("distance1 | %f\n", distance);
	distance = distance * cos(angle);
	//printf("distance2 | %f\n", distance);

	// printf("==================\n");
	// printf("px,py | %f %f\n", data->player_pos.x,data->player_pos.y);
	// printf("distance3 | %f\n", distance);
	// printf("angle | %f\n", angle);
	// printf("angle_offset | %f\n", angle_offset);
	// printf("==================\n");
	float temp = 2000.0/(distance/8);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < temp; j++)
		{
			// printf("math = %d\n", GAME_WIDTH * j + i);
			if (angle >= 0)
				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - (int)temp/2) + (i + GAME_WIDTH/2 + (int)(angle * 180 / PI * 23) - 4/2)] = shade_colour(GREEN, distance/16);
			else
			{
				// printf("math = %d\n", GAME_WIDTH * (j + GAME_HEIGHT/4) + (i + GAME_WIDTH/4 - (int)fabs(angle * 180 / PI * 2)));
				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - (int)temp/2) + (i + GAME_WIDTH/2 - (int)fabs(angle * 180 / PI * 23) - 4/2)] = shade_colour(GREEN, distance/16);
			}
		}
	}

	// sqrt (x2 - x1)^2 + (y2-y1)^2
}

//void	draw_player_direction(t_data *data, float angle)
//{
//	float	ray_x;
//	float	ray_y;
//	float	temp_x;
//	float	temp_y;
//	float	max;
//
//	// printf("=========================\n");
//	printf("fov_x = %f\n", data->fov.x);
//	printf("fov_y = %f\n", data->fov.y);
//	printf("player_direction = %f\n", data->player_direction);
//	temp_x = data->fov.x;
//	temp_y = data->fov.y;
//	//printf("cos = %f\n", cos(angle + data->player_direction));
//	//printf("sin = %f\n", sin(angle + data->player_direction));
//	ray_x = cos(angle + data->player_direction) * data->fov.x - sin(angle + data->player_direction) * data->fov.y;
//	ray_y = sin(angle + data->player_direction) * data->fov.x + cos(angle + data->player_direction) * data->fov.y;
//	//printf("ray_x = %f\n", ray_x);
//	//printf("ray_y = %f\n", ray_y);
//	// printf("=========================\n");
//
//	max = fmax(fabs(ray_x), fabs(ray_y));
//	//printf("max = %f\n", max);
//	ray_x /= max;
//	ray_y /= max;
//	//printf("ray_x = %f\n", ray_x);
//	//printf("ray_y = %f\n", ray_y);
//	while (1)
//	{
//		// int math = WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x);
//		//printf("%d %d\n",((int)data->player_pos.y + (int)temp_y), ((int)data->player_pos.x + (int)temp_x));
//		if (data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] != GREEN)
//				// data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] != GRAY)
//			data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] = RED;
//		else
//		{
//			draw_game(data, (data->player_pos.x + temp_x), (data->player_pos.y + temp_y), angle);
//			// data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] = BLUE;
//			break;
//		}
//		//printf("temp_x = %f\n", temp_x);
//		//printf("temp_y = %f\n", temp_y);
//		temp_x += ray_x;
//		temp_y += ray_y;
//		// data->player_pos.x += ray_x;
//		// data->player_pos.y += ray_y;
//	}
//}

void	draw_player_direction(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	float	max;

	ray_x = data->player_pos.x;
	ray_y = data->player_pos.y;

	dx = cos(angle) * data->fov.x - sin(angle) * data->fov.y;
	dy = sin(angle) * data->fov.x + cos(angle) * data->fov.y;

	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (1)
	{
		if (data->img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] != GREEN)
			data->img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] = RED;
		else
		{
			draw_game(data, ray_x, ray_y, angle);
			break;
		}
		ray_x += dx;
		ray_y += dy;
	}
}

void	draw_fov(t_data *data)
{
	float	angle;

	angle = 0;
	//printf("==================\n");
	//draw_player_direction(data, 0);
	//draw_player_direction(data, 0.5);
	//draw_player_direction(data, -0.5);
	//printf("==================\n");
	//draw_player_direction(data, PI * 5 / 180);
	//draw_player_direction(data, PI * 6 / 180);
	//draw_player_direction(data, PI * 7 / 180);
	//draw_player_direction(data, PI * 8 / 180);
	//printf("==================\n");
	//draw_player_direction(data, -PI * 5 / 180);
	//draw_player_direction(data, -PI * 6 / 180);
	//draw_player_direction(data, -PI * 7 / 180);
	//draw_player_direction(data, -PI * 8 / 180);
	//exit(0);
	//printf("==================\n");
	// draw_player_direction(data, 0.5);
	// draw_player_direction(data, -0.5 + (2* PI));
	// if (angle < 0)
	// 	angle += 2 * PI;
	// draw_player_direction(data, -0.5);
	// draw_player_direction(data, 2*PI - 0.5);
	// draw_player_direction(data, -0.5);

	//exit(0);
	// draw_player_direction(data, PI * 20/180);
	// draw_player_direction(data, PI * 30/180);


	while (angle < (PI * 30/180))
	{
		draw_player_direction(data, angle);
		draw_player_direction(data, -angle);
		angle += (PI * 0.1/180);
	}
}

void	draw_sky(t_data *data)
{
	for (int i = 0; i < GAME_WIDTH; i++)
	{
		for (int j = 0; j < GAME_HEIGHT; j++)
		{
			if (j > GAME_HEIGHT / 2)
				data->game.data[GAME_WIDTH * j + i] = BROWN;
			else
				data->game.data[GAME_WIDTH * j + i] = LBLUE;
		}
	}
}

void	scale_image(t_data *data)
{
	int	scale;

	scale = 2;
	for (int i = 0; i < XPM_SIZE * scale; i++)
	{
		for (int j = 0; j < XPM_SIZE * scale; j++)
		{
			if (j % scale == 0)
				data->game.data[GAME_WIDTH * j + i] = data->wall.data[XPM_SIZE * j/scale + i/scale];
			else
				data->game.data[GAME_WIDTH * j + i] = data->wall.data[XPM_SIZE * (j-j%scale)/scale + (i-i%scale)/scale];
		}
	}
}

int	draw_loop(t_data *data)
{
	//draw_tiles(data);
	//draw_player(data);
	//draw_sky(data);
	//draw_fov(data);
	scale_image(data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->wall.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->game.img, WIDTH, 0);
	//mlx_put_image_to_window(data->mlx, data->win, data->game.img, WIDTH + 10, 0);
	return (0);
}

int	main()
{
	t_data	data;
	int  map[ROW][COL] =  {
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  1 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	0 ,  0 ,  0 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 }
	};

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 2500, 1080, "cub3d");
	ft_memcpy(data.map, map, sizeof(int) * ROW * COL);

	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = (int*)mlx_get_data_addr(data.img.img,
			&data.img.bpp, &data.img.line_size, &data.img.endian);

	data.game.img = mlx_new_image(data.mlx, GAME_WIDTH, GAME_HEIGHT);
	data.game.data = (int*)mlx_get_data_addr(data.game.img,
			&data.game.bpp, &data.game.line_size, &data.game.endian);

	data.wall.img = mlx_xpm_file_to_image(data.mlx, "./test.xpm", &data.wall.width, &data.wall.height);
	data.wall.data = (int*)mlx_get_data_addr(data.wall.img,
			&data.wall.bpp, &data.wall.line_size, &data.wall.endian);

	// printf("bpp = %d\n", data.img.bpp);
	// printf("line_size = %d\n", data.img.line_size);
	// printf("endian = %d\n", data.img.endian);

	//data.player_pos.x = 48;
	//data.player_pos.y = 306;
	////data.player_direction = 3.921593;
	//data.player_direction = -PI/2;
	//data.fov.x = cos(data.player_direction);
	//data.fov.y = sin(data.player_direction);

	//printf("%f\n", data.fov.x);
	//printf("%f\n", data.fov.y);

	//// shade_colour("0xFF0000", 19);

	mlx_hook(data.win, X_KEY_PRESS, 0, handle_key, &data);
	mlx_hook(data.win, X_KEY_EXIT, 0, handle_exit, &data);

	mlx_loop_hook(data.mlx, draw_loop, &data);
	mlx_loop(data.mlx);
}


// https://stdbc.tistory.com/62

// we render from x -> y so our coordinate axis is rotated

//      -PI/2 
//  PI          0
//       PI/2
//
//
//
//      -PI/2 
//  PI/2        0  PI/2
//       PI/2
