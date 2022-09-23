#include "fractol.h"

void	select_change_color(t_data *m_data, t_bool is_right)
{
	if (is_right)
	{
		if (m_data->img.animation_mod == 3)
			m_data->img.animation_mod = 1;
		else
			m_data->img.animation_mod++;
	}
	else
	{
		if (m_data->img.animation_mod == 1)
			m_data->img.animation_mod = 3;
		else
			m_data->img.animation_mod--;
	}
}

int	flash(t_data *mlx_data)
{
	unsigned int	x;
	unsigned int	y;
	char			*pos;

	if (!mlx_data->img.is_animated)
		return(0);
	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			pos = mlx_data->img.addr + (y * mlx_data->img.line_len + x * (mlx_data->img.bpp/8));
			if (*(unsigned int *)pos <= 0x0)
				*(unsigned int *)pos = COLOR_MIN;
			else
				*(unsigned int *)pos = *(unsigned int *)pos - DE_COLOR;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->img.mlx_img, 0, 0);
	return(0);
}

int color_change(t_data *m_data) {
	if (!m_data->img.is_animated)
	{
		if (m_data->img.animation_mod == 1)
			flash(m_data);
	}
}
