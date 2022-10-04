/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:40:41 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/26 14:40:42 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	is_in_fractal(t_data m_data, char *pos)
{
	if (m_data.mod == 1 || m_data.mod == 2)
		*(unsigned int *)pos = 0xFFFFFF / ((m_data.zc.z.rl * 10000) / \
		(m_data.zc.z.im * 10000));
	else if (m_data.mod == 3)
		*(unsigned int *)pos = 0xFFFFFF / (m_data.zc.z.rl * 10000) / \
		(m_data.zc.z.im * 10000);
}

void	is_out_fractal(char *pos, unsigned int i)
{
	*(unsigned int *)pos = 0x00000000 + i * 0x010101 * 2;
}

static void	set_min_de_color(t_data *m_data, int color_canal, char mod)
{
	if (color_canal == 0xFE)
	{
		m_data->img.color_min -= 0xFE * pow(256, mod);
		m_data->img.decolor -= 0x01 * pow(256, mod);
	}
	else if (color_canal == 0)
	{
		m_data->img.color_min += 0xFE * pow(256, mod);
		m_data->img.decolor += 0x01 * pow(256, mod);
	}
}

void	cut_rgb_canal(t_data *m_data, int key)
{
	t_rgb	min_rgb;

	min_rgb = int_to_rgb(m_data->img.color_min);
	if (key == R_KEY)
		set_min_de_color(m_data, min_rgb.r, 2);
	else if (key == G_KEY)
		set_min_de_color(m_data, min_rgb.g, 1);
	else if (key == B_KEY)
		set_min_de_color(m_data, min_rgb.b, 0);
}
