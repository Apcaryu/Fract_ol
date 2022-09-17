#include "fractol.h"

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

void	z_dz(double *min, double *max, double tmp, int key, t_bool is_inf)
{
	if (is_inf)
	{
		if (key == 4)
			as_tmp(min, max, tmp, false);
		else if (key == 5)
			as_tmp(min, max, tmp, true);
	}
	else 
	{
		if (key == 4)
			as_tmp(min, max, tmp, true);
		else if (key == 5)
			as_tmp(min, max, tmp, false);
	}
}

void	mouse_zoom(t_data *m_data, int key)
{
	double	tmp;

	if (m_data->mouse_pos.x_pos < WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, true);
		z_dz(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, key, true);
	}
	else if (m_data->mouse_pos.x_pos > WIN_X / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.x_pos, WIN_X, false);
		z_dz(&m_data->fractal.min_x, &m_data->fractal.max_x, tmp, key, false);
	}
	if (m_data->mouse_pos.y_pos < WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, true);
		z_dz(&m_data->fractal.min_y, &m_data->fractal.max_y, tmp, key, true);
	}
	else if (m_data->mouse_pos.y_pos > WIN_Y / 2)
	{
		tmp = tmp_calcul(*m_data, m_data->mouse_pos.y_pos, WIN_Y, false);
		z_dz(&m_data->fractal.min_y, &m_data->fractal.max_y, tmp, key, false);
	}
}
