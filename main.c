#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world");
	//mlx_pixel_put(mlx, mlx_win, 500, 500, 0x00FFFFFF);
	mandelbrot(mlx, mlx_win, 50);
	mlx_loop(mlx);
}