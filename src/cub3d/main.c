#include "cub3d.h"
#include "libft.h"

int	handle_key(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_Q)
	{
		data->player_direction -= 0.13;
		if (data->player_direction < 0)
			data->player_direction += 2 * PI;
		data->fov.x = cos(data->player_direction);
		data->fov.y = sin(data->player_direction);
	}
	if (keycode == KEY_E)
	{
		data->player_direction += 0.13;
		if (data->player_direction > 2 * PI)
			data->player_direction += 2 * PI;
		data->fov.x = cos(data->player_direction);
		data->fov.y = sin(data->player_direction);
	}
	if (keycode == KEY_W)
	{
		if (data->img.data[(WIDTH * ((int)data->player_pos.y - MOVE_GAP - 5)) + (int)data->player_pos.x] != GREEN)
			data->player_pos.y -= MOVE_GAP;
	}
	if (keycode == KEY_A)
	{
		if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x - MOVE_GAP - 5)] != GREEN)
			data->player_pos.x -= MOVE_GAP;
	}
	if (keycode == KEY_S)
	{
		if (data->img.data[(WIDTH * ((int)data->player_pos.y + MOVE_GAP + 5)) + (int)data->player_pos.x] != GREEN)
			data->player_pos.y += MOVE_GAP;
	}
	if (keycode == KEY_D)
	{
		if (data->img.data[(WIDTH * ((int)data->player_pos.y)) + ((int)data->player_pos.x + MOVE_GAP + 5)] != GREEN)
			data->player_pos.x += MOVE_GAP;
	}
	if (keycode == KEY_ESC)
		exit(0);
	printf("Player Pos = %f,%f\n",data->player_pos.x, data->player_pos.y);
	//printf("Player direction = %f\n", data->player_direction);
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
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, GREEN);
			else
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, WHITE);
			draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, GRAY);
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

void	draw_player_direction(t_data *data)
{
	double	ray_x;
	double	ray_y;
	double	temp_x;
	double	temp_y;

	// printf("x = %f\n", data->fov.x);
	// printf("y = %f\n", data->fov.y);
	temp_x = data->fov.x;
	temp_y = data->fov.y;
	ray_x = cos(data->player_direction) * data->fov.x - sin(data->player_direction) * data->fov.y;
	ray_y = sin(data->player_direction) * data->fov.x + cos(data->player_direction) * data->fov.y;
	// printf("ray_x = %f\n", ray_x);
	// printf("ray_y = %f\n", ray_y);
//	i = 0;
	while (1)
	{
		// int math = WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x);
		//printf("%d %d\n",((int)data->player_pos.y + (int)temp_y), ((int)data->player_pos.x + (int)temp_x));
		if (data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] != GREEN)
			data->img.data[WIDTH * ((int)data->player_pos.y + (int)temp_y) + ((int)data->player_pos.x + (int)temp_x)] = BLUE;
		else
			break;
		// printf("temp_x = %f\n", temp_x);
		// printf("tempyx = %f\n", temp_y);
		temp_x += ray_x;
		temp_y += ray_y;
		// data->player_pos.x += ray_x;
		// data->player_pos.y += ray_y;
	}
}

int	draw_loop(t_data *data)
{
	draw_tiles(data);
	draw_player(data);
	draw_player_direction(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	main()
{
	t_data	data;
	int  map[ROW][COL] =  {
	{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  1 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  0 ,	1 },
	{ 1 ,  1 ,	1 ,  1 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 ,  0 ,  1 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  1 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
	{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	0 ,  0 ,  0 ,  1 ,	1 ,  1 ,  1 ,  0 ,	1 },
	{ 1 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	0 ,  0 ,  0 ,  0 ,	1 },
	{ 1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 ,  1 ,  1 ,  1 ,	1 }
	};

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	ft_memcpy(data.map, map, sizeof(int) * ROW * COL);

	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = (int*)mlx_get_data_addr(data.img.img,
			&data.img.bpp, &data.img.line_size, &data.img.endian);

	// printf("bpp = %d\n", data.img.bpp);
	// printf("line_size = %d\n", data.img.line_size);
	// printf("endian = %d\n", data.img.endian);

	data.player_pos.x = 144;
	data.player_pos.y = 144;
	data.player_direction = -PI/2;
	data.fov.x = cos(data.player_direction);
	data.fov.y = sin(data.player_direction);

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
