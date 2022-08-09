#include "fractol.h"

int input_test(int key, t_data mlx_data)
{
	printf("key = %d\n", key);
}

int	esc_key(int key, t_data *mlx_data)
{
	if (key==0xFF1B)
    	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
}

int	user_input(int key, t_data *mlx_data)
{
	if (key==4)
	{
		// mlx_data->img.zoom = mlx_data->img.zoom + 1;
		printf("zoom = %d\n", &(mlx_data->img.zoom));
		// mandelbrot2(mlx_data, 50, mlx_data->img.zoom);
	}
}