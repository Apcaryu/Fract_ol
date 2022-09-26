#include "color.h"

t_rgb	select_convertion(t_rgb rgb, double r_mod, double g_mod, double b_mod)
{
	rgb.r = r_mod;
	rgb.g = g_mod;
	rgb.b = b_mod;
	return (rgb);
}