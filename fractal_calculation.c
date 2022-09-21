#include "fractol.h"

unsigned int is_in(t_data *m_data, unsigned int iter)
{
	unsigned int i;

	while (pow(m_data->zc.z.rl, 2) + pow(m_data->zc.z.im, 2) < 4 && i < iter)
	{
		m_data->zc.z = add_cmplx(power_cmplx(m_data->zc.z, 2), m_data->zc.c);
		i++;
	}
	return (i);
}

void	calculate_fractal(t_data *m_data, unsigned int iter, t_fractal fractal, t_bool mod)
{
	char	*pos;
	t_xy	pos_xy;
	unsigned int i;

	pos_xy.x = 0;
	while (pos_xy.x < m_data->fractal.zoom_x)
	{
		pos_xy.y = 0;
		while (pos_xy.y < m_data->fractal.zoom_y)
		{
			pos = m_data->img.addr + (pos_xy.y * m_data->img.line_len + pos_xy.x * (m_data->img.bpp/8));
			init_zc(m_data, pos_xy, fractal);
			i = is_in(m_data, iter);
			if (i == iter)
				is_in_fractal(*m_data, pos);
			else
				is_out_fractal(*m_data, pos, i);
			pos_xy.y++;
		}
		pos_xy.x++;
	}
	mlx_put_image_to_window(m_data->mlx, m_data->mlx_window, m_data->img.mlx_img, 0, 0);
}
