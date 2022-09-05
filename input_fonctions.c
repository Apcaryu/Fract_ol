#include "fractol.h"

int input_test(int key)
{
	printf("key = %d\n", key);
}

int	esc_key(int key, t_data *mlx_data)
{
	if (key==0xFF1B)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img.mlx_img);
    	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		mlx_loop_end(mlx_data->mlx);
	}
}

int	user_input(int key, int x, int y, t_data *mlx_data)
{
	printf("Mouse pos = %d | %d\n", x, y);
	/* ------- Up Arrow ------- */
	if (key==4/*65362*/)
	{
		printf("Up arrow\n");
		mlx_data->img.zoom = mlx_data->img.zoom + 1;
		// printf("zoom = %d\n", mlx_data->img.zoom);
		if(mlx_data->mod == 1)
			mandelbrot2(mlx_data, 5000);
		else if (mlx_data->mod == 2)
			julia(mlx_data, 5000);
		// mandelbrot2(mlx_data, 5000);
		// julia(mlx_data, 5000);
	}

	/* ------- Down Arrow ------- */
	else if (key==5/*65364*/)
	{
		printf("Down arrow\n");
		if (mlx_data->img.zoom > 1)
		{
			mlx_data->img.zoom = mlx_data->img.zoom - 1;
			// printf("zoom = %d\n", mlx_data->img.zoom);
			if(mlx_data->mod == 1)
				mandelbrot2(mlx_data, 5000);
			else if (mlx_data->mod == 2)
				julia(mlx_data, 5000);
		}
	}

	/* ------- Esc ------- */
	else if (key==0xFF1B)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img.mlx_img);
    	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		mlx_loop_end(mlx_data->mlx);
	}

	/* ------ Left click ------*/
	else if (key==1)
	{
		color_change(mlx_data);
	}
}