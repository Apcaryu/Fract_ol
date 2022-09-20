#include "fractol.h"

void	init_fractal(t_data *m_data)
{
	m_data->fractal.min_x /= (m_data->img.zoom * m_data->img.zoom);
	m_data->fractal.max_x /= (m_data->img.zoom * m_data->img.zoom);
	m_data->fractal.min_y /= (m_data->img.zoom * m_data->img.zoom);
	m_data->fractal.max_y /= (m_data->img.zoom * m_data->img.zoom);
	m_data->fractal.image_x = WIN_X;
	m_data->fractal.image_y = WIN_Y;
	m_data->fractal.zoom_x = m_data->fractal.image_x / \
	(m_data->fractal.max_x - m_data->fractal.min_x);
	m_data->fractal.zoom_y = m_data->fractal.image_y / \
	(m_data->fractal.max_y - m_data->fractal.min_y);
}
