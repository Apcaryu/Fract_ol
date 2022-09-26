#include "color.h"

/*
 * Is a function for hsv_to_rgb
 */
t_rgb	select_convertion(t_rgb rgb, double r_mod, double g_mod, double b_mod)
{
	rgb.r = r_mod;
	rgb.g = g_mod;
	rgb.b = b_mod;
	return (rgb);
}

int	set_rgb(t_rgb rgb_color, unsigned char min, unsigned char max, \
unsigned char diff)
{
	int	h_out;

	if (max == 0 && min == 0)
		h_out = 0;
	else if (max == rgb_color.r)
		h_out = fmod(60 * ((rgb_color.g - rgb_color.b) / \
		(double)diff) + 360, 360);
	else if (max == rgb_color.g)
		h_out = fmod(60 * ((rgb_color.b - rgb_color.r) / \
		(double)diff) + 120, 360);
	else if (max == rgb_color.b)
		h_out = fmod(60 * ((rgb_color.r - rgb_color.g) / \
		(double)diff) + 240, 360);
	return (h_out);
}