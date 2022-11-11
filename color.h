/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:12:33 by apellegr          #+#    #+#             */
/*   Updated: 2022/11/11 01:09:46 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <math.h>

typedef struct s_hsv
{
	int		h;
	double	s;
	double	v;
}	t_hsv;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

t_rgb		hsv_to_rgb(t_hsv hsv_color);
t_hsv		rgb_to_hsv(t_rgb rgb_color);
int			rgb_to_int(t_rgb rgb_color);
t_rgb		int_to_rgb(unsigned int int_color);

t_rgb		select_convertion(double r_mod, double g_mod, double b_mod);
int			set_rgb(t_rgb rgb_color, unsigned char min, unsigned char max, \
unsigned char diff);

#endif