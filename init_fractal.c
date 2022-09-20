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
