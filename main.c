/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:58:27 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/26 14:58:28 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_data	mlx_data;

	if (argc <= 1 || 4 < argc)
		fractol_man();
	else if (2 <= argc && argc <= 4)
	{
		fractal_type(argc, argv, &mlx_data);
		base_init(&mlx_data);
		fractal_run(&mlx_data, 50 * mlx_data.mod);
		mlx_hook(mlx_data.mlx_window, 17, StructureNotifyMask, \
		&win_close, &mlx_data);
		mlx_key_hook(mlx_data.mlx_window, key, &mlx_data);
		mlx_mouse_hook(mlx_data.mlx_window, user_input, &mlx_data);
		mlx_loop_hook(mlx_data.mlx, &color_change, &mlx_data);
		mlx_loop(mlx_data.mlx);
	}
}
