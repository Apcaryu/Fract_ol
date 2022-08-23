#include "color.h"

t_rgb	hsv_to_rgb(t_hsv hsv_color)
{
	t_rgb	color_out;
	double	max;
	double	min;
	double	z;
    double tmp;

	max = 255 * hsv_color.v;
	min = max * (1 - hsv_color.s);
	z = round((max - min) * (1 - fabs(fmod(hsv_color.h / 60.0, 2) - 1)) + 1);

	if (0 <= hsv_color.h && hsv_color.h < 60)
	{
		color_out.r = max;
		color_out.g = z + min;
		color_out.b = min;
	}
	else if (60 <= hsv_color.h && hsv_color.h < 120)
	{
		color_out.r = z + min;
		color_out.g = max;
		color_out.b = min;
	}
	else if (120 <= hsv_color.h && hsv_color.h < 180)
	{
		color_out.r = min;
		color_out.g = max;
		color_out.b = z + min;
	}
	else if (180 <= hsv_color.h && hsv_color.h < 240)
	{
		color_out.r = min;
		color_out.g = z + min;
		color_out.b = max;
	}
	else if (240 <= hsv_color.h && hsv_color.h < 300)
	{
		color_out.r = z + min;
		color_out.g = min;
		color_out.b = max;
	}
	else if (300 <= hsv_color.h && hsv_color.h < 360)
	{
		color_out.r = max;
		color_out.g = min;
		color_out.b = z + min;
	}
	return(color_out);
}

t_hsv	rgb_to_hsv(t_rgb rgb_color)
{
	t_hsv color_out;
	unsigned char	max;
	unsigned char	min;
	unsigned char	diff;

	if(rgb_color.r >= rgb_color.g && rgb_color.r >= rgb_color.b)
		max = rgb_color.r;
	else if (rgb_color.g >= rgb_color.r && rgb_color.g >= rgb_color.b)
		max = rgb_color.g;
	else
		max = rgb_color.b;
	
	if(rgb_color.r <= rgb_color.g && rgb_color.r <= rgb_color.b)
		min = rgb_color.r;
	else if (rgb_color.g <= rgb_color.r && rgb_color.g <= rgb_color.b)
		min = rgb_color.g;
	else
		min = rgb_color.b;
	
	diff = max - min;

	color_out.v = (double)max/(double)255;

	if (max > 0)
		color_out.s = 1.0 - (double)min / (double)max;
	else
		color_out.s = 0;

	if (max == 0 && min == 0)
		color_out.h = 0;
	else if (max == rgb_color.r)
		color_out.h = fmod(60 * ((double)(rgb_color.g - rgb_color.b) / (double)diff) + 360, 360);
	else if (max == rgb_color.g)
		color_out.h = fmod(60 * ((double)(rgb_color.b - rgb_color.r) / (double)diff) + 120, 360);
	else if (max == rgb_color.b)
		color_out.h = fmod(60 * ((double)(rgb_color.r - rgb_color.g) / (double)diff) + 240, 360);
	
	return(color_out);
}

int		rgb_to_int(t_rgb rgb_color)
{
	int	color_out;

	color_out = 256 * 256 * rgb_color.r + 256 * rgb_color.g + rgb_color.b;
	return(color_out);
}

t_rgb	int_to_rgb(int int_color)
{
	t_rgb 			color_out;
	
	color_out.r = (int_color / (256 * 256));
	color_out.g = ((int_color / 256) % 256);
	color_out.b = int_color % 256;

	return(color_out);
}