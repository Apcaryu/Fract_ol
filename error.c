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

void	julia_setup(t_data *m_data, int argc, char *argv[])
{
	if (argc == 3)
	{
		m_data->zc.c.rl = ft_atof(argv[2]);
		m_data->zc.c.im = 0.0;
	}
	else if (argc == 4)
	{
		m_data->zc.c.rl = ft_atof(argv[2]);
		m_data->zc.c.im = ft_atof(argv[3]);
	}
	else
	{
		m_data->zc.c.rl = -0.76;
		m_data->zc.c.im = 0.12;
	}
}

void	fractal_type(int argc, char *argv[], t_data *mlx_data)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		mlx_data->mod = 1;
	else if (!ft_strncmp(argv[1], "burningship", ft_strlen("burningship")))
		mlx_data->mod = 3;
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	{
		mlx_data->mod = 2;
		julia_setup(mlx_data, argc, argv);
	}
	else
	{
		fractol_man();
		exit(EXIT_SUCCESS);
	}
}
