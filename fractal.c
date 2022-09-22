#include "fractol.h"
#include <stdio.h>

void	mandelbrot2(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF; /*0x004600FA;*/ /*0x00202020;*/

	unsigned int	x = 0;
	unsigned int	y;
	t_fractal fractal;
	fractal = init_fractal(mlx_data);
	int	i;
	iter = iter * mlx_data->img.zoom;
	while (x < mlx_data->fractal.image_x)
	{
		y = 0;
		while (y < mlx_data->fractal.image_y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			mlx_data->zc.c.rl = x/mlx_data->fractal.zoom_x+fractal.min_x;
			mlx_data->zc.c.im = y/mlx_data->fractal.zoom_y+fractal.min_y;
			mlx_data->zc.z.rl = 0;
			mlx_data->zc.z.im = 0;
			i = 0;
			
			while(pow(mlx_data->zc.z.rl, 2) + pow(mlx_data->zc.z.im, 2) < 4 && i < iter)
			{
				mlx_data->zc.z = add_cmplx(power_cmplx(mlx_data->zc.z, 2), mlx_data->zc.c);
				// z = add_cmplx(power_cmplx(z, 7), c);
				i++;
			}
			if (i == iter)
				*(unsigned int *)pos = white/* / (z.rl *10000) / (z.im * 10000)*/ / ((mlx_data->zc.z.rl * 10000) / (mlx_data->zc.z.im * 10000));
			else
				*(unsigned int *)pos = 0x00000000 + i  * 0x010101;
				// *(unsigned int *)pos = rose/*i;*/ * (100 * i/iter) * (100 * x/ image_x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
}

void	julia(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF; /*0x004600FA;*/ /*0x00202020;*/

	printf("min_x %f | max_x %f\n", mlx_data->fractal.min_x, mlx_data->fractal.max_x);
	printf("min_y %f | max_y %f\n", mlx_data->fractal.min_y, mlx_data->fractal.max_y);
	// printf("min_x %f | max_x %f\n", min_x, max_x);
	// printf("min_y %f | max_y %f\n", min_y, max_y);
	printf("zoom = %f", mlx_data->img.zoom);

	unsigned int	x = 0;
	unsigned int	y = 0;

	t_fractal fractal;
	fractal = init_fractal(mlx_data);
	int	i;

	t_rgb rgb;
	int color_int;
	iter = iter * mlx_data->img.zoom;
//	printf("c_r = %f | c_i = %f", mlx_data->zc.c.rl, mlx_data->zc.c.im);
	while (x < mlx_data->fractal.image_x)
	{
		y = 0;
		while (y < mlx_data->fractal.image_y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			// c.rl = /*0.35*//*-0.63*//*0.35*/-0.76/*0.285*/;
			// c.im = /*-0.36*//*-0.4*//*0.05*/0.12/*0.013*/;
			mlx_data->zc.z.rl = x/mlx_data->fractal.zoom_x+fractal.min_x;//1.5;
			mlx_data->zc.z.im = y/mlx_data->fractal.zoom_y+fractal.min_y;
			i = 0;
			
			while(mlx_data->zc.z.rl * mlx_data->zc.z.rl + mlx_data->zc.z.im * mlx_data->zc.z.im < 4 && i < iter)
			{
				mlx_data->zc.z = add_cmplx(power_cmplx(mlx_data->zc.z, 2), mlx_data->zc.c);
				// z = add_cmplx(power_cmplx(z, 4), c);
				i++;
			}
			if (i == iter)
			{
				rgb = int_to_rgb(0xFFFFFF);
				rgb.r = rgb.r * (100*x/WIN_X) / (double)(100*y/WIN_Y);
				rgb.g = rgb.g * (100*x/WIN_X) / (double)(100*y/WIN_Y);
				rgb.b = rgb.b * (100*x/WIN_X) / (double)(100*y/WIN_Y);
				color_int = rgb_to_int(rgb);
				*(unsigned int *)pos = /*color_int*/white / ((mlx_data->zc.z.rl * 10000) / (mlx_data->zc.z.im * 10000));
				// *(unsigned int *)pos = white / (z.rl * 10000) / (z.im * 10000 + 1);
				// printf("int: %d | hex: %X", *(unsigned int *)pos, *(unsigned int *)pos);
			}
			else
			{
				// choose_color(pos, i, iter);
				*(unsigned int *)pos = 0x00000000 + i * DE_COLOR * 2;
				// *(unsigned int *)pos = 0x00FF0000/*rose*//*/i;*/ * (100 * i/iter) * (100 * x/ image_x);
				// printf("int: %d | hex: %X\n", *(unsigned int *)pos, *(unsigned int *)pos);
			}
			y++;
		}
		x++;
	}
	// printf("int : %d, hex : %X", 584, 584);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
}

int	color_change(t_data *mlx_data)
{
	unsigned int	x;
	unsigned int	y;
	char			*pos;
	long long int	test;
	
	test = 0;
	// while (test < 53775807)
	// {
	// 	test++;
	// }
	
	if (!mlx_data->img.is_animated)
		return(0); 
	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			/*if (*(unsigned int *)pos == 0xFFFFFF)
			{

			}
			else */if (*(unsigned int *)pos <= 0x0)
			{
				*(unsigned int *)pos = COLOR_MIN;
			}
			else
				*(unsigned int *)pos = *(unsigned int *)pos - DE_COLOR;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
	return(0);
}
/*
int	color_change(t_data *mlx_data)
{
	unsigned int	x;
	unsigned int	y;
	char			*pos;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			if (*(unsigned int *)pos == 0xFFFFFF)
			{
				*(unsigned int *)pos = rand();
			}
			else if (*(unsigned int *)pos <= 0x0)
			{
				*(unsigned int *)pos = 0x010101;
			}
			else
				*(unsigned int *)pos = *(unsigned int *)pos - DE_COLOR;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
	return(0);
}
*/
/*
int	color_change(t_data *mlx_data)
{
	unsigned int	x;
	unsigned int	y;
	char			*pos;
	t_rgb			rgb;
	t_hsv			hsv;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			rgb = int_to_rgb(*(unsigned int *)pos);
			hsv = rgb_to_hsv(rgb);
			if (hsv.h >= 360)
			{
				hsv.h = 0;
			}
			else
			{
				hsv.h = hsv.h + 2;
				if (hsv.h >= 360)
					hsv.h = 0;
			}
			rgb = hsv_to_rgb(hsv);
			*(unsigned int *)pos = rgb_to_int(rgb);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
	return(0);
}
*/
unsigned int	choose_color(char *pos, int i, int iter)
{
	float	taux;

	taux = (100*i)/(double)iter;
	taux *= 100;
	if (taux < 30)
		*(unsigned int *)pos = 0xB33E97 * (taux/100) /** ((100*i/(double)iter))*/;
	else if (taux < 55)
		*(unsigned int *)pos = 0xFFE97D  * (taux/100)/** ((100*i/(double)iter))*/;
	else if (taux < 75)
		*(unsigned int *)pos = 0xFF73DE * (taux/100)/** ((100*i/(double)iter))*/;
	else if (taux < 90)
		*(unsigned int *)pos = 0x59FFFC * (taux/100)/** ((100*i/(double)iter))*/;
	else
		*(unsigned int *)pos = 0x47B3B1 * (taux/100)/** ((100*i/(double)iter))*/;
	return(0);
}