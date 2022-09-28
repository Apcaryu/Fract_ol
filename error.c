/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:14:52 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/20 18:14:54 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	check_args(char *argv[])
{
	int		cmp_res;
	char	mod;
	int		size_arg;

	size_arg = ft_strlen(argv[1]);
	cmp_res = ft_strncmp(argv[1], "mandelbrot", size_arg);
	if (!cmp_res)
		mod = 1;
	else if (!ft_strncmp(argv[1], "julia", size_arg))
		mod = 2;
	else
		mod = 0;
	return (mod);
}

void	fractal_type(int argc, char *argv[], t_data *mlx_data)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot"/*argv[1]*/)))
		mlx_data->mod = 1;
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	{
		mlx_data->mod = 2;
		if (argc == 3)
		{
			mlx_data->zc.c.rl = ft_atof(argv[2]);
			mlx_data->zc.c.im = 0.0;
		}
		else if (argc == 4)
		{
			mlx_data->zc.c.rl = ft_atof(argv[2]);
			mlx_data->zc.c.im = ft_atof(argv[3]);
		}
		else
		{
			mlx_data->zc.c.rl = -0.76;
			mlx_data->zc.c.im = 0.12;
		}
	}
	else
	{
		fractol_man();
		exit(EXIT_SUCCESS);
	}
}
