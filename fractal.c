#include "fractol.h"
#include <stdio.h>

void	set_color(char *pos, int i, int i_max)
{
	float	percent_i;

	percent_i = 100 * i / i_max;
	if(percent_i < 5)
	{
		*(unsigned int *)pos = 0x00B34695;
	}
	else if (percent_i < 10)
	{
		*(unsigned int *)pos = 0x00FF96E3;
	}
	else if (percent_i < 20)
	{
		*(unsigned int *)pos = 0x00FF7CDB;
	}
	else if (percent_i < 40)
	{
		*(unsigned int *)pos = 0x0048B334;
	}
	else if (percent_i < 100)
	{
		*(unsigned int *)pos = 0x0092FF7D;
	}
}

void	mandelbrot2(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF; /*0x004600FA;*/ /*0x00202020;*/

	float	min_x = -2.1 / mlx_data->img.zoom;
	float	max_x = 0.6 / mlx_data->img.zoom;
	float	min_y = -1.2 / mlx_data->img.zoom;
	float	max_y = 1.2 / mlx_data->img.zoom;
	//printf("zoom = %d\n", mlx_data->img.zoom);
	// float	zoom = 100; //100 pixel pour une unite
	
	int	image_x = WIN_X;
	int image_y = WIN_Y;
	double zoom_x = image_x/(max_x - min_x);
	double zoom_y = image_y/(max_y - min_y);

	unsigned int	x = 0;
	unsigned int	y = 0;

	double c_r;
	double c_i;
	double	z_r = 0;
	double	z_i = 0;
	int	i = 0;
	double	tmp = z_r;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));

			c_r = x/zoom_x+min_x;
			c_i = y/zoom_y+min_y;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;

			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i = i + 1;

			while (((z_r * z_r + z_i * z_i) < 4) && i < iter)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = 2 * tmp * z_i + c_i;
				i = i + 1;
			}
			if (i == iter)
			{
				*(unsigned int *)pos = white / ((z_r * 10000) / (z_i * 10000));
				// pos = *(unsigned int *)pos & 0x00FFFFFF;
				// printf("x: %d | y: %d | color: %x\n", x, y, pos);
			}
			else
			{
				// set_color(pos, i, iter);
				*(unsigned int *)pos = rose/*/i;*/ * (100 * i/iter) * (100 * x/ image_x);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
}