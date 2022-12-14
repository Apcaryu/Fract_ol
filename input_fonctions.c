/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:54:10 by apellegr          #+#    #+#             */
/*   Updated: 2022/11/11 02:03:10 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	win_close(t_data *m_data)
{
	exit_program(m_data);
	return (0);
}

int	key(int key, t_data *mlx_data)
{
	if (key == ESCAPE_KEY)
	{
		exit_program(mlx_data);
	}
	else if (key == SPACE_KEY)
		mlx_data->img.is_animated = !mlx_data->img.is_animated;
	else if (key == RIGHT_ARROW)
	{
		select_change_color(mlx_data, true);
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	else if (key == LEFT_ARROW)
	{
		select_change_color(mlx_data, false);
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	else if (mlx_data->img.animation_mod == 1 && \
	(key == R_KEY || key == G_KEY || key == B_KEY))
	{
		cut_rgb_canal(mlx_data, key);
	}
	return (0);
}

int	user_input(int key, int x, int y, t_data *mlx_data)
{
	mlx_data->key = key;
	mlx_data->mouse_pos.x_pos = x;
	mlx_data->mouse_pos.y_pos = y;
	if (key == SCROLL_UP)
	{
		mlx_data->img.zoom = mlx_data->img.zoom + 0.1;
		mouse_zoom(mlx_data);
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	else if (key == SCROLL_DOWN)
	{
		mouse_zoom(mlx_data);
		if (mlx_data->img.zoom > 0.2)
			mlx_data->img.zoom = mlx_data->img.zoom - 0.1;
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	return (0);
}
