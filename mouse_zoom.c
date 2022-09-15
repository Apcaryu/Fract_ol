#include "fractol.h"

double	tmp_calcul(t_data m_data, int pos, int win, t_bool is_min)
{
	double	tmp;

	if (is_min)
	{
		tmp = (100 * pos / (win / 2.0)) / 100.0;
		tmp = 1 - tmp;
		tmp *= log(m_data.img.zoom);
	}
	else
	{
		tmp = pos - win / 2.0;
		tmp = (100 * tmp / (win / 2.0)) / 100.0;
		tmp *= log(m_data.img.zoom);
	}
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

void	mouse_zoom(t_data *m_data, int key)
{
	double	tmp;

	if (m_data->mouse_pos.x_pos < WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, true);
		if (key == 4)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, false);
		else if (key == 5)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, true);
	}
	else if (m_data->mouse_pos.x_pos > WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, false);
		if (key == 4)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, true);
		else if (key == 5)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, false);
	}
	if (m_data->mouse_pos.y_pos < WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, true);
		if (key == 4)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, false);
		else if (key == 5)
			as_tmp(&m_data->fractal.min_y, &m_data->fractal.max_y, tmp, true);
	}
	else if (m_data->mouse_pos.y_pos > WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, false);
		if (key == 4)
			as_tmp(&m_data->fractal.min_y, &m_data->fractal.max_y, tmp, true);
		else if (key == 5)
			as_tmp(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, false);
	}
}
