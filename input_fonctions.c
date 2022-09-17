#include "fractol.h"

int input_test(int key)
{
	printf("key = %d\n", key);
}

int	key(int key, t_data *mlx_data)
{
	printf("key = %d\n", key);
	if (key==0xFF1B)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img.mlx_img);
    	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		mlx_loop_end(mlx_data->mlx);
	}
	if (key == SPACE_KEY)
		mlx_data->img.is_animated = !mlx_data->img.is_animated;
	
}

int	user_input(int key, int x, int y, t_data *mlx_data)
{
	mlx_data->key = key;
	mlx_data->mouse_pos.x_pos = x;
	mlx_data->mouse_pos.y_pos = y;
	printf("key = %d\n", key);
	printf("Mouse pos = %d | %d\n", x, y);
	/* ------- Up Scrol ------- */
	if (key==4/*65362*/)
	{
		printf("Up scrol\n");
		mlx_data->img.zoom = mlx_data->img.zoom + 0.1;
		/*mlx_data->fractal.min_x -= 0.1;
		mlx_data->fractal.max_x += .1;
		mlx_data->fractal.min_y -= 0.2;
		mlx_data->fractal.max_y += .2;*/
		mouse_zoom(mlx_data);
		// printf("zoom = %d\n", mlx_data->img.zoom);
		if(mlx_data->mod == 1)
			mandelbrot2(mlx_data, 50);
		else if (mlx_data->mod == 2)
			julia(mlx_data, 5000);
		// mandelbrot2(mlx_data, 5000);
		// julia(mlx_data, 5000);
	}

	/* ------- Down Scrol ------- */
	else if (key==5/*65364*/)
	{
		printf("Down scrol\n");
		mouse_zoom(mlx_data);
		if (mlx_data->img.zoom > 0.2)
			mlx_data->img.zoom = mlx_data->img.zoom - 0.1;
		if(mlx_data->mod == 1)
			mandelbrot2(mlx_data, 50);
		else if (mlx_data->mod == 2)
			julia(mlx_data, 5000);
		/*if (mlx_data->img.zoom > 1)
		{
			mlx_data->img.zoom = mlx_data->img.zoom - 0.1;
			// printf("zoom = %d\n", mlx_data->img.zoom);
			if(mlx_data->mod == 1)
				mandelbrot2(mlx_data, 50);
			else if (mlx_data->mod == 2)
				julia(mlx_data, 50);
		}*/
	}

	/* ------- Esc ------- */
	else if (key==0xFF1B)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img.mlx_img);
    	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		mlx_destroy_display(mlx_data->mlx);
		mlx_loop_end(mlx_data->mlx);
	}

	/* ------ Left click ------*/
	else if (key==1)
	{
		mlx_data->img.is_animated = !mlx_data->img.is_animated;
	}
}