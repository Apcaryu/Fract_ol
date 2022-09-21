#include "fractol.h"

void	calculate_fractal(t_data *m_data, unsigned int iter, t_bool mod)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < m_data->fractal.zoom_x)
	{
		y = 0;
		while (y < m_data->fractal.zoom_y)
		{

			y++;
		}
		x++;
	}
}
