/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:54:55 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/26 14:54:56 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	base_init(t_data *m_data)
{
	m_data->mlx = mlx_init();
	m_data->mlx_window = mlx_new_window(m_data->mlx, WIN_X, WIN_Y, "Fractal");
	m_data->img.mlx_img = mlx_new_image(m_data->mlx, WIN_X, WIN_Y);
	m_data->img.addr = mlx_get_data_addr(m_data->img.mlx_img, \
	&m_data->img.bpp, &m_data->img.line_len, &m_data->img.endian);
	m_data->img.zoom = 1;
	m_data->mouse_pos.x_pos = 0;
	m_data->mouse_pos.y_pos = 0;
	m_data->fractal.min_x = -3;
	m_data->fractal.max_x = 3;
	m_data->fractal.min_y = -3;
	m_data->fractal.max_y = 3;
	m_data->img.is_animated = false;
	m_data->img.animation_mod = 1;
}
