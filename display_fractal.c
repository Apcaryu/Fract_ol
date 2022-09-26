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
	*(unsigned int *)pos = 0xFFFFFF / ((m_data.zc.z.rl * 10000) / \
	(m_data.zc.z.im * 10000));
}

void	is_out_fractal(t_data m_data, char *pos, unsigned int i)
{
	*(unsigned int *)pos = 0x00000000 + i * 0x010101 * 2;
}

void	cut_rgb_canal(t_data *m_data, int key)
{
	if (key == R_KEY)
		printf("red\n");
	else if (key == G_KEY)
		printf("green\n");
	else if (key == B_KEY)
		printf("blue");
}
