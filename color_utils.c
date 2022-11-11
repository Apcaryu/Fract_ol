/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:40:55 by apellegr          #+#    #+#             */
/*   Updated: 2022/11/11 01:09:13 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/*
 * This function set a rgb color
 */
t_rgb	select_convertion(double r_mod, double g_mod, double b_mod)
{
	t_rgb	color_out;

	color_out.r = r_mod;
	color_out.g = g_mod;
	color_out.b = b_mod;
	return (color_out);
}

/*
 * This function convert a rgb value to hue value
 */
int	set_rgb(t_rgb rgb_color, unsigned char min, unsigned char max, \
unsigned char diff)
{
	int	h_out;

	h_out = 0;
	if (max == min)
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
