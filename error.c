#include "fractol.h"

char	check_args(char *argv[])
{
	int	cmp_res;
	char	mod;
	int	size_arg;

	size_arg = ft_strlen(argv[1]);
	cmp_res = ft_strncmp(argv[1], "mandelbrot", size_arg);
	if (!cmp_res)
	{
		mod = 1;
	}
	else if (ft_strncmp(argv[1], "julia", size_arg))
	{
		mod = 2;
	}
	else
	{
		mod = 0;
	}
	return(mod);
}