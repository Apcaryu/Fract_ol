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
	{
		printf("C'est non\n");
	}
	else if (2 <= argc && argc <= 4)
	{
		printf("LET'S GOOOOOOOO\n");
		base_init(&mlx_data);
		fractal_type(argc, argv, &mlx_data);
		fractal_run(&mlx_data, 50 * mlx_data.mod);
		mlx_hook(mlx_data.mlx_window, 17, StructureNotifyMask, \
		&win_close, &mlx_data);
		mlx_key_hook(mlx_data.mlx_window, key, &mlx_data);
		mlx_mouse_hook(mlx_data.mlx_window, user_input, &mlx_data);
		mlx_loop_hook(mlx_data.mlx, &color_change, &mlx_data);
		mlx_loop(mlx_data.mlx);
		printf("mod = %d", mlx_data.mod);
	}
}
	/* ---------- For test mlx ----------
	mlx_data.mlx = mlx_init();
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx, WIN_X, WIN_Y, "Fractal");
	mlx_data.img.mlx_img = mlx_new_image(mlx_data.mlx, WIN_X, WIN_Y);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.mlx_img, \
	 &mlx_data.img.bpp, &mlx_data.img.line_len, &mlx_data.img.endian);
	mlx_data.img.zoom = 1;
	mandelbrot2(&mlx_data, 50);
	// julia(&mlx_data, 5000);
	// color_change(&mlx_data);

	// julia(&mlx_data, 500);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world");
	// mlx_image = mlx_new_image(mlx, 1000, 1000);
	// //mlx_pixel_put(mlx, mlx_win, 500, 500, 0x00FFFFFF);
	// mandelbrot(mlx, mlx_win, mlx_image, 500);
	mlx_key_hook(mlx_data.mlx_window,esc_key,&mlx_data);
	mlx_mouse_hook(mlx_data.mlx_window,user_input,&mlx_data);
	// mlx_key_hook(mlx_data.mlx_window,input_test,0);
	// mlx_mouse_hook(mlx_data.mlx_window,input_test,0);
	mlx_loop_hook(mlx_data.mlx, &color_change, &mlx_data);
	mlx_loop(mlx_data.mlx);
	*/