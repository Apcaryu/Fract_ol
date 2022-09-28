/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:54:10 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/22 13:07:14 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int key, t_data *mlx_data)
{
	if (key == ESCAPE_KEY)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img.mlx_img);
		mlx_destroy_display(mlx_data->mlx);
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		mlx_loop_end(mlx_data->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == SPACE_KEY)
		mlx_data->img.is_animated = !mlx_data->img.is_animated;
	else if (key == RIGHT_ARROW)
	{
		fractal_run(mlx_data, 50 * mlx_data->mod);
		select_change_color(mlx_data, true);
	}
	else if (key == LEFT_ARROW)
	{
		fractal_run(mlx_data, 50 * mlx_data->mod);
		select_change_color(mlx_data, false);
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
		printf("Up scrol\n");
		mlx_data->img.zoom = mlx_data->img.zoom + 0.1;
		mouse_zoom(mlx_data);
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	else if (key == SCROLL_DOWN)
	{
		printf("Down scrol\n");
		mouse_zoom(mlx_data);
		if (mlx_data->img.zoom > 0.2)
			mlx_data->img.zoom = mlx_data->img.zoom - 0.1;
		fractal_run(mlx_data, 50 * mlx_data->mod);
	}
	return (0);
}
