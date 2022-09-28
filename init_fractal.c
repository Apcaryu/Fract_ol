/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:30:48 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/20 18:31:08 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	init_fractal(t_data *m_data)
{
	t_fractal	fractal;

	fractal.min_x = m_data->fractal.min_x / \
	(m_data->img.zoom * m_data->img.zoom);
	fractal.max_x = m_data->fractal.max_x / \
	(m_data->img.zoom * m_data->img.zoom);
	fractal.min_y = m_data->fractal.min_y / \
	(m_data->img.zoom * m_data->img.zoom);
	fractal.max_y = m_data->fractal.max_y / \
	(m_data->img.zoom * m_data->img.zoom);
	m_data->fractal.image_x = WIN_X;
	m_data->fractal.image_y = WIN_Y;
	m_data->fractal.zoom_x = m_data->fractal.image_x / \
	(fractal.max_x - fractal.min_x);
	m_data->fractal.zoom_y = m_data->fractal.image_y / \
	(fractal.max_y - fractal.min_y);
	return (fractal);
}

void	init_zc(t_data *m_data, t_xy pos_xy, t_fractal fractal)
{
	if (m_data->mod == 1 || m_data->mod == 3)
	{
		m_data->zc.z.rl = 0;
		m_data->zc.z.im = 0;
		m_data->zc.c.rl = pos_xy.x / m_data->fractal.zoom_x + fractal.min_x;
		m_data->zc.c.im = pos_xy.y / m_data->fractal.zoom_y + fractal.min_y;
	}
	else if (m_data->mod == 2)
	{
		m_data->zc.z.rl = pos_xy.x / m_data->fractal.zoom_x + fractal.min_x;
		m_data->zc.z.im = pos_xy.y / m_data->fractal.zoom_y + fractal.min_y;
	}
}
