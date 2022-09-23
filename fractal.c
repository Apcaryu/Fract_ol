#include "fractol.h"
#include <stdio.h>
/*
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
			else *//*if (*(unsigned int *)pos <= 0x0)
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
*//*
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