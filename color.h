/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:12:33 by apellegr          #+#    #+#             */
/*   Updated: 2022/08/24 15:28:29 by apellegr         ###   ########.fr       */
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

typedef struct	s_color_set
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
}	t_color_set;

t_rgb	hsv_to_rgb(t_hsv hsv_color);
t_hsv	rgb_to_hsv(t_rgb rgb_color);
int		rgb_to_int(t_rgb rgb_color);
t_rgb	int_to_rgb(int int_color);

t_color_set	set_init();

#endif