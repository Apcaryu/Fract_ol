/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:12:33 by apellegr          #+#    #+#             */
/*   Updated: 2022/08/17 15:21:29 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_rgb;

typedef	struct s_hsv
{
	unsigned int	hue;
	unsigned int	saturation;
	unsigned int	value;
}	t_hsv;

t_rgb	hsv_to_rgb(t_hsv color);
t_hsv	rgb_to_hsv(t_rgb color);

#endif