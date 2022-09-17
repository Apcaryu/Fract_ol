/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:08:57 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/17 17:09:00 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_m_and_m(t_data *m_data, t_min_max *min_max, t_bool is_x)
{
	if (is_x)
	{
		min_max->min = &m_data->fractal.min_x;
		min_max->max = &m_data->fractal.max_x;
	}
	else
	{
		min_max->min = &m_data->fractal.min_y;
		min_max->max = &m_data->fractal.max_y;
	}
}

double	tmp_calcul(t_data m_data, int pos, int win, t_bool is_min)
{
	double	tmp;

	if (is_min)
	{
		tmp = (100 * pos / (win / 2.0)) / 100.0;
		tmp = 1 - tmp;
	}
	else
	{
		tmp = pos - win / 2.0;
		tmp = (100 * tmp / (win / 2.0)) / 100.0;
	}
	tmp *= log(m_data.img.zoom);
	return (tmp);
}

void	as_tmp(double *min, double *max, double tmp, t_bool is_add)
{
	if (is_add)
	{
		*min += tmp;
		*max += tmp;
	}
	else
	{
		*min -= tmp;
		*max -= tmp;
	}
}

void	z_dz(t_data *m_data, double tmp, t_bool is_inf, t_bool is_x)
{
	t_min_max	min_max;

	init_m_and_m(m_data, &min_max, is_x);
	if (is_inf)
	{
		if (m_data->key == 4)
			as_tmp(min_max.min, min_max.max, tmp, false);
		else if (m_data->key == 5)
			as_tmp(min_max.min, min_max.max, tmp, true);
	}
	else
	{
		if (m_data->key == 4)
			as_tmp(min_max.min, min_max.max, tmp, true);
		else if (m_data->key == 5)
			as_tmp(min_max.min, min_max.max, tmp, false);
	}
}

void	mouse_zoom(t_data *m_data, int key)
{
	double	tmp;

	if (m_data->mouse_pos.x_pos < WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, true);
		z_dz(m_data, tmp, true, true);
	}
	else if (m_data->mouse_pos.x_pos > WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, false);
		z_dz(m_data, tmp, false, true);
	}
	if (m_data->mouse_pos.y_pos < WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, true);
		z_dz(m_data, tmp, true, false);
	}
	else if (m_data->mouse_pos.y_pos > WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, false);
		z_dz(m_data, tmp, false, false);
	}
}
