/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:22:16 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/28 19:05:26 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fractol_man(void)
{
	write(1, "\033[31m\e[5m/!\\--------------------/!\\\e[0m\033[37m\n", 46);
	write(1, "You made a mistake in the execution command please check the "
		"following points:\n", 80);
	write(1, "1. After the name of program you have written "
		"\033[35mmandelbrot\033[37m or \033[35mjulia\033[37m or "
		"\033[35mburningship\033[37m.\n", 113);
	write(1, "2. After julia you have written a maximum of 2 numbers which are"
		" part of the reals\n", 84);
	write(1, "3. All the parameters are separated by a space.\n", 49);
	write(1, "Examples of a valid command:\n", 30);
	write(1, "./fractol mandelbrot\n", 22);
	write(1, "./fractol burningship\n", 23);
	write(1, "./fractol julia 0.3\n", 21);
	write(1, "./fractol julia 0.3 0.6\n", 25);
}
