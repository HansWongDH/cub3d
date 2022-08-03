#include "cub3d.h"
#include "libft.h"

int	handle_key(int keycode, t_data *data)
{
	(void)data;
	//if (keycode == KEY_W)
	//if (keycode == KEY_A)
	//if (keycode == KEY_S)
	//if (keycode == KEY_D)
	if (keycode == KEY_ESC)
		exit(0);
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
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, 0xFF0000);
			else
				draw_square(data, TILE_SIZE * i, TILE_SIZE * j, 0xFFFFFF);
			draw_grid(data, TILE_SIZE * i, TILE_SIZE * j, 0x808080);
			j++;
		}
		i++;
	}
}

int	draw_loop(t_data *data)
{
	draw_tiles(data);
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

	printf("bpp = %d\n", data.img.bpp);
	printf("line_size = %d\n", data.img.line_size);
	printf("endian = %d\n", data.img.endian);

	mlx_hook(data.win, X_KEY_PRESS, 0, handle_key, &data);
	mlx_hook(data.win, X_KEY_EXIT, 0, handle_exit, &data);

	mlx_loop_hook(data.mlx, draw_loop, &data);
	mlx_loop(data.mlx);
}
