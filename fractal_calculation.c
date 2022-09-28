/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:44:57 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/26 14:44:58 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	is_in(t_data *m_data, unsigned int iter)
{
	unsigned int	i;

	i = 0;
	while (pow(m_data->zc.z.rl, 2) + pow(m_data->zc.z.im, 2) < 4 && i < iter)
	{
		m_data->zc.z = add_cmplx(power_cmplx(m_data->zc.z, 2), m_data->zc.c);
		i++;
	}
	return (i);
}

void	calculate_fractal(t_data *m_data, unsigned int iter, t_fractal fractal)
{
	char			*pos;
	t_xy			pos_xy;
	unsigned int	i;

	pos_xy.x = 0;
	while (pos_xy.x < (unsigned int)m_data->fractal.image_x)
	{
		pos_xy.y = 0;
		while (pos_xy.y < (unsigned int)m_data->fractal.image_y)
		{
			pos = m_data->img.addr + (pos_xy.y * m_data->img.line_len + \
			pos_xy.x * (m_data->img.bpp / 8));
			init_zc(m_data, pos_xy, fractal);
			i = is_in(m_data, iter);
			if (i == iter)
				is_in_fractal(*m_data, pos);
			else
				is_out_fractal(pos, i);
			pos_xy.y++;
		}
		pos_xy.x++;
	}
	mlx_put_image_to_window(m_data->mlx, m_data->mlx_window, \
	m_data->img.mlx_img, 0, 0);
}

void	fractal_run(t_data *m_data, unsigned int iter)
{
	t_fractal	fractal;

	fractal = init_fractal(m_data);
	iter *= m_data->img.zoom;
	calculate_fractal(m_data, iter, fractal);
}
