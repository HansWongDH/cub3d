//#include "cub3d.h"
//#include "libft.h"

//int shade_colour(int colour, int percent)
//{
//	(void)percent;
//	int i = 0;
//	while (i++ < percent)
//		colour = ((colour & 0x7E7E7E) >> 1) | (colour & 0x808080);
//	return (colour);
//}

//int	handle_key(int keycode, t_data *data)
//{
//	float	to_move_x;
//	float	to_move_y;
//
//	if (keycode == KEY_W)
//	{
//		printf("================\n");
//		printf("fov_x = %f\n", data->fov.x);
//		printf("fov_y = %f\n", data->fov.y);
//
//		to_move_x = ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.x + data->player_pos.x);
//		to_move_y = ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.y + data->player_pos.y);
//
//		printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
//		printf("to_move_x = %f\n", to_move_x);
//		printf("to_move_y = %f\n", to_move_y);
//		//for (int i = 0; i < 5; i++)
//		//{
//		if (data->img.data[(WIDTH * (int)to_move_y + (int)to_move_y)] == GREEN)
//		{
//			printf("WALL\n");
//			return 0;
//		}
//		//}
//		data->player_pos.x += data->fov.x * MOVE_GAP;
//		data->player_pos.y += data->fov.y * MOVE_GAP;
//		printf("================\n");
//	}
//	if (keycode == KEY_A)
//	{
//		//if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x - MOVE_GAP - 5)] != GREEN)
//		//	data->player_pos.x -= MOVE_GAP;
//		data->player_direction -= PI/72;
//		if (data->player_direction < 0)
//			data->player_direction += 2 * PI;
//		data->fov.x = cos(data->player_direction);
//		data->fov.y = sin(data->player_direction);
//	}
//	if (keycode == KEY_S)
//	{
//		//if (data->img.data[(WIDTH * ((int)data->player_pos.y + MOVE_GAP + 5)) + (int)data->player_pos.x] != GREEN)
//		//	data->player_pos.y += MOVE_GAP;
//
//		//data->player_pos.x -= (data->fov.x * MOVE_GAP);
//		//data->player_pos.y -= (data->fov.y * MOVE_GAP);
//
//		printf("================\n");
//		printf("fov_x = %f\n", data->fov.x);
//		printf("fov_y = %f\n", data->fov.y);
//
//		to_move_x = data->player_pos.x - ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.x);
//		to_move_y = data->player_pos.y - ((PLAYER_SIZE/2 + MOVE_GAP) * data->fov.y);
//
//		printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
//		printf("to_move_x = %f\n", to_move_x);
//		printf("to_move_y = %f\n", to_move_y);
//		//for (int i = 0; i < 5; i++)
//		//{
//		if (data->img.data[(WIDTH * (int)to_move_y + (int)to_move_y)] == GREEN)
//		{
//			printf("WALL\n");
//			return 0;
//		}
//		//}
//		data->player_pos.x -= data->fov.x * MOVE_GAP;
//		data->player_pos.y -= data->fov.y * MOVE_GAP;
//		printf("================\n");
//	}
//	if (keycode == KEY_D)
//	{
//		//if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x + MOVE_GAP + 5)] != GREEN)
//		//	data->player_pos.x += MOVE_GAP;
//		data->player_direction += PI/72;
//		if (data->player_direction > 2 * PI)
//			data->player_direction -= 2 * PI;
//		data->fov.x = cos(data->player_direction);
//		data->fov.y = sin(data->player_direction);
//	}
//	if (keycode == KEY_ESC)
//		exit(0);
//	printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
//	printf("Player direction = %f\n", data->player_direction);
//	return (0);
//}

//int	handle_exit(int keycode, t_data *data)
//{
//	(void)data;
//	(void)keycode;
//	exit(0);
//}

//void	draw_square(t_data *data, int i, int j, int colour)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	while (x < TILE_SIZE)
//	{
//		y = 0;
//		while (y < TILE_SIZE)
//		{
//			data->img.data[WIDTH * (x + i) + (y + j)] = colour;
//			y++;
//		}
//		x++;
//	}
//}

//void	draw_grid(t_data *data, int i, int j, int colour)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	while (x < TILE_SIZE)
//	{
//		y = 0;
//		if (x == 0 || x == TILE_SIZE)
//		{
//			while (y < TILE_SIZE)
//			{
//				data->img.data[WIDTH * (i) + (y + j)] = colour;
//				y++;
//			}
//		}
//		else
//			data->img.data[WIDTH * (i + x) + (j)] = colour;
//		x++;
//	}
//}
//
//void	draw_tiles(t_data *data)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	while (i < ROW)
//	{
//		j = 0;
//		while (j < COL)
//		{
//			if (data->map[i][j] == 1)
//			{
//				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, GREEN);
//				//draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, GRAY);
//			}
//			else
//			{
//				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, WHITE);
//				//draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, BLACK);
//			}
//			j++;
//		}
//		i++;
//	}
//}
//
//void	draw_player(t_data *data)
//{
//	int	i;
//	int	j;
//	int	player_size;
//
//	player_size = 10;
//	i = 0;
//	while (i < player_size)
//	{
//		j = 0;
//		while (j < player_size)
//		{
//			data->img.data[WIDTH * ((int)data->player_pos.y + j - (player_size / 2)) +
//				((int)data->player_pos.x + i - (player_size / 2))] = PINK;
//			j++;
//		}
//		i++;
//	}
//}

//t_direction	get_direction_of_ray(float player_direction, float angle_offset)
//{
//	float	angle;
//
//	angle = get_positive_value_of_angle(player_direction + angle_offset);
//	if (angle > 5 * PI / 4 && angle <= 7 * PI / 4)
//		return (NORTH);
//	if ((angle > 7 * PI / 4 && angle <= 2 * PI)
//			|| (angle >= 0 && angle <= PI / 4))
//		return (EAST);
//	if (angle > PI / 4 && angle <= 3 * PI / 4)
//		return (SOUTH);
//	return (WEST);
//}
//
//float		get_x_offset_for_tile_position(t_direction direction, float x, float y)
//{
//	if (direction == NORTH || direction == SOUTH)
//		return (fmodf(x / TILE_SIZE, 1) * XPM_SIZE);
//	return (fmodf(y / TILE_SIZE, 1) * XPM_SIZE);
//}
//
//void	draw_game(t_data *data, float x, float y, float angle)
//{
//	float		distance;
//	int			y_scale;
//	float		x_offset;
//	t_direction	direction;
//
//	distance = sqrt(pow(data->player_pos.x - x, 2) + pow(data->player_pos.y - y, 2));
//	distance = distance * cos(angle);
//	y_scale = Y_INV_SCALE/distance;
//
//	direction = get_direction_of_ray(data->player_direction, angle);
//	x_offset = get_x_offset_for_tile_position(direction, x, y);
//	for (int i = 0; i < X_SCALE; i++)
//	{
//		for (int j = 0; j < y_scale; j++)
//		{
//			if (direction == NORTH)
//				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - y_scale/2)
//				+ (i + GAME_WIDTH/2 + (int)(angle * 180 / PI * 24) - X_SCALE/2)] =
//					data->north_wall.data[XPM_SIZE * (int)((float)j/(float)y_scale * 64) + (int)x_offset];
//			else if (direction == EAST)
//				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - y_scale/2) + (i + GAME_WIDTH/2 + (int)(angle * 180 / PI * 24) - X_SCALE/2)] =
//					data->east_wall.data[XPM_SIZE * (int)((float)j/(float)y_scale * 64) + (int)x_offset];
//			else if (direction == WEST)
//				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - y_scale/2) + (i + GAME_WIDTH/2 + (int)(angle * 180 / PI * 24) - X_SCALE/2)] =
//					data->west_wall.data[XPM_SIZE * (int)((float)j/(float)y_scale * 64) + (int)x_offset];
//			else if (direction == SOUTH)
//				data->game.data[GAME_WIDTH * (j + GAME_HEIGHT/2 - y_scale/2) + (i + GAME_WIDTH/2 + (int)(angle * 180 / PI * 24) - X_SCALE/2)] =
//					data->south_wall.data[XPM_SIZE * (int)((float)j/(float)y_scale * 64) + (int)x_offset];
//		}
//	}
//}
//
//void	draw_player_direction(t_data *data, float angle)
//{
//	float	ray_x;
//	float	ray_y;
//	float	dx;
//	float	dy;
//	float	max;
//
//	ray_x = data->player_pos.x;
//	ray_y = data->player_pos.y;
//
//	dx = cos(angle) * data->fov.x - sin(angle) * data->fov.y;
//	dy = sin(angle) * data->fov.x + cos(angle) * data->fov.y;
//
//	max = fmax(fabs(dx), fabs(dy));
//	dx /= max;
//	dy /= max;
//	while (1)
//	{
//		if (data->img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] != GREEN)
//			data->img.data[WIDTH * (int)floor(ray_y) + (int)floor(ray_x)] = RED;
//		else
//		{
//			draw_game(data, ray_x, ray_y, angle);
//			break;
//		}
//		ray_x += dx;
//		ray_y += dy;
//	}
//}
//
//void	draw_fov(t_data *data)
//{
//	float	angle;
//
//	angle = 0;
//	//printf("==================\n");
//	draw_player_direction(data, PI * 0.1/180);
//	draw_player_direction(data, 0);
//	draw_player_direction(data, PI * -0.1/180);
//	//printf("==================\n");
//
//	while (angle < (PI * 30/180))
//	{
//		draw_player_direction(data, angle);
//		draw_player_direction(data, -angle);
//		angle += (PI * 0.1/180);
//	}
//}
//
//void	draw_sky(t_data *data)
//{
//	for (int i = 0; i < GAME_WIDTH; i++)
//	{
//		for (int j = 0; j < GAME_HEIGHT; j++)
//		{
//			if (j > GAME_HEIGHT / 2)
//				data->game.data[GAME_WIDTH * j + i] = FLOORCOL;
//			else
//				data->game.data[GAME_WIDTH * j + i] = CIELCOL;
//		}
//	}
//}
//
//void	scale_image(t_data *data)
//{
//	int	x_scale = 1;
//	int	y_scale = 10;
//
//	for (int i = 0; i < XPM_SIZE * x_scale; i++)
//	{
//		for (int j = 0; j < XPM_SIZE * y_scale; j++)
//		{
//			if (j % y_scale== 0)
//				data->game.data[GAME_WIDTH * j + i] = data->north_wall.data[XPM_SIZE * j/y_scale + i/x_scale];
//			else
//				data->game.data[GAME_WIDTH * j + i] = data->north_wall.data[XPM_SIZE * (j-j%y_scale)/y_scale + (i-i%x_scale)/x_scale];
//		}
//	}
//}
//
//void	put_images(t_data *data)
//{
//	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->north_wall.img, XPM_SIZE, HEIGHT);
//	mlx_put_image_to_window(data->mlx, data->win, data->east_wall.img, XPM_SIZE * 2, HEIGHT + XPM_SIZE);
//	mlx_put_image_to_window(data->mlx, data->win, data->south_wall.img, XPM_SIZE, HEIGHT + 2 * XPM_SIZE);
//	mlx_put_image_to_window(data->mlx, data->win, data->west_wall.img, 0, HEIGHT + XPM_SIZE);
//	mlx_put_image_to_window(data->mlx, data->win, data->game.img, WIDTH + 10, 0);
//}
//
//int	draw_loop(t_data *data)
//{
//	draw_tiles(data);
//	draw_player(data);
//	draw_sky(data);
//	draw_fov(data);
//	put_images(data);
//	return (0);
//}
//
//void	init_images(t_data *data)
//{
//	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//	data->img.data = (int*)mlx_get_data_addr(data->img.img,
//			&data->img.bpp, &data->img.line_size, &data->img.endian);
//
//	data->game.img = mlx_new_image(data->mlx, GAME_WIDTH, GAME_HEIGHT);
//	data->game.data = (int*)mlx_get_data_addr(data->game.img,
//			&data->game.bpp, &data->game.line_size, &data->game.endian);
//}
//
//void	init_xpm(t_data *data)
//{
//	data->north_wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_North.xpm", &data->north_wall.width, &data->north_wall.height);
//	data->north_wall.data = (int*)mlx_get_data_addr(data->north_wall.img,
//			&data->north_wall.bpp, &data->north_wall.line_size, &data->north_wall.endian);
//
//	data->east_wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_East.xpm", &data->east_wall.width, &data->east_wall.height);
//	data->east_wall.data = (int*)mlx_get_data_addr(data->east_wall.img,
//			&data->east_wall.bpp, &data->east_wall.line_size, &data->east_wall.endian);
//
//	data->south_wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/SUPPORT_5B.xpm", &data->south_wall.width, &data->south_wall.height);
//	data->south_wall.data = (int*)mlx_get_data_addr(data->south_wall.img,
//			&data->south_wall.bpp, &data->south_wall.line_size, &data->south_wall.endian);
//
//	data->west_wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/Labwall_West.xpm", &data->west_wall.width, &data->west_wall.height);
//	data->west_wall.data = (int*)mlx_get_data_addr(data->west_wall.img,
//			&data->west_wall.bpp, &data->west_wall.line_size, &data->west_wall.endian);
//}
//
//void	init_player_info(t_data *data)
//{
//	data->player_pos.x = 80;
//	data->player_pos.y = 80;
//	data->player_direction = -PI/2;
//	data->fov.x = cos(data->player_direction);
//	data->fov.y = sin(data->player_direction);
//}
//
//void	init_data(t_data *data)
//{
//	data->mlx = mlx_init();
//	data->win = mlx_new_window(data->mlx, 2500, 1080, "cub3d");
//	init_images(data);
//	init_xpm(data);
//	init_player_info(data);
//}
//
//void	start_game(t_data *data)
//{
//	mlx_hook(data->win, X_KEY_PRESS, 0, handle_key, data);
//	mlx_hook(data->win, X_KEY_EXIT, 0, handle_exit, data);
//	mlx_loop_hook(data->mlx, draw_loop, data);
//	mlx_loop(data->mlx);
//}

//int	main()
//{
//	t_data	data;
//	int  map[ROW][COL] =  {
//		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  1 ,	1 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
//		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	0 ,  0 ,  0 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
//		{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
//		{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 }
//	};
//
//	ft_memcpy(data.map, map, sizeof(int) * ROW * COL);
//
//	init_data(&data);
//	start_game(&data);
//}


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

