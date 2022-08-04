#include "fractol.h"
#include <stdio.h>

void	mandelbrot(void *mlx, void *mlx_win, void *mlx_image, unsigned int iter)
{
	int		*pos;
	int		nb_bits;
	int		s_line;
	char	*mlx_data_addr = mlx_get_data_addr(mlx_image, &nb_bits, &s_line, pos);
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF;

	float	min_x = -2.1;
	float	max_x = 0.6;
	float	min_y = -1.2;
	float	max_y = 1.2;
	unsigned int	zoom = 100; //100 pixel pour une unite
	
	int	image_x = 1000;
	int image_y = 1000;
	double zoom_x = image_x/(max_x - min_x);
	double zoom_y = image_y/(max_y - min_y);

	//float	image_x = (max_x - min_x) * zoom;
	//float	image_y = (max_y - min_y) * zoom;

	unsigned int	x = 0;
	unsigned int	y = 0;

	double c_r = x/zoom+min_x;
	double c_i = y/zoom+min_y;
	double	z_r = 0;
	double	z_i = 0;
	int	i = 0;
	double	tmp = z_r;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			// double	c_r = x / zoom + min_x;
			// double	c_i = y / zoom + min_y;
			pos = mlx_image + (y * s_line + x * (nb_bits/8));
			

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
				// mlx_data_addr = &pos;
				*(unsigned int *)pos = white;
				// mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFFFF);
				// printf("x = %d | y = %d\n", x, y);
			}
			else
			{
				// mlx_data_addr = &pos;
				*(unsigned int *)pos = rose;
				mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF00FF);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, mlx_image, 0, 0);
}

void	mandelbrot2(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF;

	float	min_x = -2.1;
	float	max_x = 0.6;
	float	min_y = -1.2;
	float	max_y = 1.2;
	unsigned int	zoom = 100; //100 pixel pour une unite
	
	int	image_x = 1000;
	int image_y = 1000;
	double zoom_x = image_x/(max_x - min_x);
	double zoom_y = image_y/(max_y - min_y);

	unsigned int	x = 0;
	unsigned int	y = 0;

	double c_r = x/zoom+min_x;
	double c_i = y/zoom+min_y;
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
				*(unsigned int *)pos = white;
			}
			else
			{
				*(unsigned int *)pos = rose;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
}