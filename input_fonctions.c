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