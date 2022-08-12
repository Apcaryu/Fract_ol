#include "fractol.h"
#include "complex.h"
#include <stdio.h>

void	mandelbrot2(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF; /*0x004600FA;*/ /*0x00202020;*/

	float	min_x = -2.1 / mlx_data->img.zoom;
	float	max_x = 0.6 / mlx_data->img.zoom;
	float	min_y = -1.2 / mlx_data->img.zoom;
	float	max_y = 1.2 / mlx_data->img.zoom;
		
	int	image_x = WIN_X;
	int image_y = WIN_Y;
	double zoom_x = image_x/(max_x - min_x);
	double zoom_y = image_y/(max_y - min_y);

	unsigned int	x = 0;
	unsigned int	y = 0;

	t_cmplx	c;
	t_cmplx z;
	int	i = 0;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			c.rl = x/zoom_x+min_x;
			c.im = y/zoom_y+min_y;
			z.rl = 0;
			z.im = 0;
			i = 0;
			
			while(z.rl * z.rl + z.im * z.im < 4 && i < iter)
			{
				z = add_cmplx(multiply_cmplx(z, z), c);
				i++;
			}
			if (i == iter)
				*(unsigned int *)pos = white / ((z.rl * 10000) / (z.im * 10000));
			else
				*(unsigned int *)pos = rose/*/i;*/ * (100 * i/iter) * (100 * x/ image_x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
}