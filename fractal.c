#include "fractol.h"
#include <stdio.h>
/*
void	mouse_zoom(t_data *mlx_data, int key)
{
	double tmp;

	if (mlx_data->mouse_pos.x_pos < WIN_X / 2)
	{
		tmp = (100*mlx_data->mouse_pos.x_pos/(WIN_X / 2.0))/100.0;
		tmp = 1 - tmp;
		tmp *= log(mlx_data->img.zoom);
		// tmp = mlx_data->fractal.min_x * tmp;
		if (key == 4)
		{
			mlx_data->fractal.min_x = mlx_data->fractal.min_x - tmp;
			mlx_data->fractal.max_x = mlx_data->fractal.max_x - tmp;
		}
		else if (key == 5)
		{
			mlx_data->fractal.min_x = mlx_data->fractal.min_x + tmp;
			mlx_data->fractal.max_x = mlx_data->fractal.max_x + tmp;
		}
	}
	else if (mlx_data->mouse_pos.x_pos > WIN_X / 2)
	{
		tmp = mlx_data->mouse_pos.x_pos - WIN_X / 2;
		tmp = (100*tmp/(WIN_X/2.0))/100.0;
		tmp *= log(mlx_data->img.zoom);
		// tmp = mlx_data->fractal.max_x * tmp;
		if (key == 4)
		{
			mlx_data->fractal.min_x = mlx_data->fractal.min_x + tmp;
			mlx_data->fractal.max_x = mlx_data->fractal.max_x + tmp;
		}
		else if (key == 5)
		{
			mlx_data->fractal.min_x = mlx_data->fractal.min_x - tmp;
			mlx_data->fractal.max_x = mlx_data->fractal.max_x - tmp;
		}
	}
	// mlx_data->mouse_pos.x_pos = pow(tmp, 2);

	if (mlx_data->mouse_pos.y_pos < WIN_Y / 2)
	{
		tmp = (100*mlx_data->mouse_pos.y_pos/(WIN_Y / 2.0))/100.0;
		tmp = 1 - tmp;
		tmp *= log(mlx_data->img.zoom);
		// tmp = mlx_data->fractal.min_y * tmp;
		if (key == 4)
		{
			mlx_data->fractal.min_y = mlx_data->fractal.min_y - tmp;
			mlx_data->fractal.max_y = mlx_data->fractal.max_y - tmp;
		}
		else if (key == 5)
		{
			mlx_data->fractal.min_y = mlx_data->fractal.min_y + tmp;
			mlx_data->fractal.max_y = mlx_data->fractal.max_y + tmp;
		}
	}
	else if (mlx_data->mouse_pos.y_pos > WIN_Y / 2)
	{
		tmp = mlx_data->mouse_pos.y_pos - WIN_Y / 2;
		tmp = (100*tmp/(WIN_X/2.0))/100.0;
		tmp *= log(mlx_data->img.zoom);
		// tmp = mlx_data->fractal.max_y * tmp;
		if (key == 4)
		{
			mlx_data->fractal.min_y = mlx_data->fractal.min_y + tmp;
			mlx_data->fractal.max_y = mlx_data->fractal.max_y + tmp;
		}
		else if (key == 5)
		{
			mlx_data->fractal.min_y = mlx_data->fractal.min_y - tmp;
			mlx_data->fractal.max_y = mlx_data->fractal.max_y - tmp;
		}
	}

	mlx_data->fractal.min_x *= mlx_data->img.zoom;
	mlx_data->fractal.max_x *= mlx_data->img.zoom;
	mlx_data->fractal.min_y *= mlx_data->img.zoom;
	mlx_data->fractal.max_y *= mlx_data->img.zoom;
}*/

void	mandelbrot2(t_data *mlx_data, unsigned int iter)
{
	char		*pos;
	unsigned int white = 0x00FFFFFF;
	unsigned int rose = 0x00FF00FF; /*0x004600FA;*/ /*0x00202020;*/

	double	min_x = mlx_data->fractal.min_x / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	max_x = mlx_data->fractal.max_x / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	min_y = mlx_data->fractal.min_y / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	max_y = mlx_data->fractal.max_y / (mlx_data->img.zoom * mlx_data->img.zoom);
		
	int	image_x = WIN_X;
	int image_y = WIN_Y;
	double zoom_x = image_x/(max_x - min_x);
	double zoom_y = image_y/(max_y - min_y);

	unsigned int	x = 0;
	unsigned int	y = 0;

	t_cmplx	c;
	t_cmplx z;
	int	i = 0;
	iter = iter * mlx_data->img.zoom;
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
				// z = add_cmplx(power_cmplx(z, 7), c);
				i++;
			}
			if (i == iter)
				*(unsigned int *)pos = white/* / (z.rl *10000) / (z.im * 10000)*/ / ((z.rl * 10000) / (z.im * 10000));
			else
				*(unsigned int *)pos = 0x00000000 + i  * 0x010101;
				// *(unsigned int *)pos = rose/*/i;*/ * (100 * i/iter) * (100 * x/ image_x);
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

	double	min_x = mlx_data->fractal.min_x / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	max_x = mlx_data->fractal.max_x / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	min_y = mlx_data->fractal.min_y / (mlx_data->img.zoom * mlx_data->img.zoom);
	double	max_y = mlx_data->fractal.max_y / (mlx_data->img.zoom * mlx_data->img.zoom);

	printf("min_x %f | max_x %f\n", mlx_data->fractal.min_x, mlx_data->fractal.max_x);
	printf("min_y %f | max_y %f\n", mlx_data->fractal.min_y, mlx_data->fractal.max_y);
	// printf("min_x %f | max_x %f\n", min_x, max_x);
	// printf("min_y %f | max_y %f\n", min_y, max_y);
	printf("zoom = %f", mlx_data->img.zoom);
	// mlx_data->fractal.min_x = min_x;
	// mlx_data->fractal.max_x = max_x;
	// mlx_data->fractal.min_y = min_y;
	// mlx_data->fractal.max_y = max_y;

	int		image_x = WIN_X;
	int		image_y = WIN_Y;
	double	zoom_x = image_x/(max_x - min_x);
	double	zoom_y = image_y/(max_y - min_y);

	unsigned int	x = 0;
	unsigned int	y = 0;

	t_cmplx	c;
	t_cmplx z;
	int	i = 0;

	t_rgb rgb;
	int color_int;
	c.rl = mlx_data->zc.c.rl;
	c.im = mlx_data->zc.c.im;
	iter = iter * mlx_data->img.zoom;
	// printf("c_r = %f | c_i = %f", c.rl, c.im);
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			// c.rl = /*0.35*//*-0.63*//*0.35*/-0.76/*0.285*/;
			// c.im = /*-0.36*//*-0.4*//*0.05*/0.12/*0.013*/;
			z.rl = x/zoom_x+min_x;//1.5;
			z.im = y/zoom_y+min_y;
			i = 0;
			
			while(z.rl * z.rl + z.im * z.im < 4 && i < iter)
			{
				z = add_cmplx(multiply_cmplx(z, z), c);
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
				*(unsigned int *)pos = /*color_int*/white / ((z.rl * 10000) / (z.im * 10000));
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
	while (test < 53775807)
	{
		test++;
	}

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