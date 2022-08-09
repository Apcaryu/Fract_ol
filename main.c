#include "fractol.h"

int	main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*mlx_win;
	// void	*mlx_image;
	t_data	mlx_data;

	mlx_data.mlx = mlx_init();
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx, WIN_X, WIN_Y, "Fractal");
	mlx_data.img.mlx_img = mlx_new_image(mlx_data.mlx, WIN_X, WIN_Y);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.mlx_img, &mlx_data.img.bpp, &mlx_data.img.line_len, &mlx_data.img.endian);
	mandelbrot2(&mlx_data, 50, atoi(argv[1]));
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world");
	// mlx_image = mlx_new_image(mlx, 1000, 1000);
	// //mlx_pixel_put(mlx, mlx_win, 500, 500, 0x00FFFFFF);
	// mandelbrot(mlx, mlx_win, mlx_image, 500);
	mlx_key_hook(mlx_data.mlx_window,esc_key,0);
	mlx_key_hook(mlx_data.mlx_window,input_test,0);
	mlx_mouse_hook(mlx_data.mlx_window,input_test,0);
	mlx_loop(mlx_data.mlx);
}