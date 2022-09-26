/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:15:31 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/23 13:15:34 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	flash(t_data *mlx_data, t_xy pos_xy)
{
	char			*pos;

	pos = mlx_data->img.addr + (pos_xy.y * mlx_data->img.line_len + \
	pos_xy.x * (mlx_data->img.bpp / 8));
	if (*(unsigned int *)pos <= 0x0)
		*(unsigned int *)pos = COLOR_MIN;
	else
		*(unsigned int *)pos = *(unsigned int *)pos - DE_COLOR;
}

void	galaxy(t_data *mlx_data, t_xy pos_xy)
{
	char			*pos;

	pos = mlx_data->img.addr + (pos_xy.y * mlx_data->img.line_len + \
	pos_xy.x * (mlx_data->img.bpp / 8));
	if (*(unsigned int *)pos == 0xFFFFFF)
		*(unsigned int *)pos = rand();
	else if (*(unsigned int *)pos <= 0x0)
		*(unsigned int *)pos = 0x010101;
	else
		*(unsigned int *)pos = *(unsigned int *)pos - DE_COLOR;
}

void	hsv_cycle(t_data *mlx_data, t_xy pos_xy)
{
	char			*pos;
	t_rgb			rgb;
	t_hsv			hsv;

	pos = mlx_data->img.addr + (pos_xy.y * mlx_data->img.line_len + \
	pos_xy.x * (mlx_data->img.bpp / 8));
	rgb = int_to_rgb(*(unsigned int *)pos);
	hsv = rgb_to_hsv(rgb);
	if (hsv.h >= 360)
		hsv.h = 0;
	else
	{
		hsv.h = hsv.h + 2;
		if (hsv.h >= 360)
			hsv.h = 0;
	}
	rgb = hsv_to_rgb(hsv);
	*(unsigned int *)pos = rgb_to_int(rgb);
}

int	color_change(t_data *m_data)
{
	t_xy	pos_xy;

	if (!m_data->img.is_animated)
	{
		pos_xy.x = 0;
		while (pos_xy.x < WIN_X)
		{
			pos_xy.y = 0;
			while (pos_xy.y < WIN_Y)
			{
				if (m_data->img.animation_mod == 1)
					flash(m_data, pos_xy);
				else if (m_data->img.animation_mod == 2)
					galaxy(m_data, pos_xy);
				else if (m_data->img.animation_mod == 3)
					hsv_cycle(m_data, pos_xy);
				pos_xy.y++;
			}
			pos_xy.x++;
		}
		mlx_put_image_to_window(m_data->mlx, m_data->mlx_window, \
		m_data->img.mlx_img, 0, 0);
	}
	return (0);
}