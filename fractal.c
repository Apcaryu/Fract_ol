#include "fractol.h"
#include <stdio.h>

void	mandelbrot(void *mlx, void *mlx_win, unsigned int iter)
{
	float	min_x = -2.1;
	float	max_x = 0.6;
	float	min_y = -1.2;
	float	max_y = 1.2;
	unsigned int	zoom = 100; //100 pixel pour une unite

	float	image_x = (max_x - min_x) * zoom;
	float	image_y = (max_y - min_y) * zoom;

	unsigned int	x = 0;
	unsigned int	y = 0;
	while (x < image_x)
	{
		while (y < image_y)
		{
			double	c_r = x / zoom + min_x;
			double	c_i = y / zoom + min_y;
			double	z_r = 0;
			double	z_i = 0;
			double	i = 0;
			double	tmp = z_r;

			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i = i + 1;

			while ((z_r * z_r + z_i * z_i < 4) && i < iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * tmp * z_i + c_i;
				i = i + 1;
			}
			if (i == iter)
			{
				mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFFFF);
				printf("x = %u | y = %u\n", x, y);
			}
			y++;
		}
		x++;
	}
}
