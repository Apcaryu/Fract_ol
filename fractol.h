/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:01:13 by apellegr          #+#    #+#             */
/*   Updated: 2022/08/10 17:45:59 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

// ---------- lib for test -----------
# include <stdlib.h>
# include <stdio.h>
// -----------------------------------
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		zoom;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	t_img	img;
}	t_data;

/* -----------------------------
	fonction pour les fractal 
   ----------------------------- */
void	mandelbrot(void *mlx, void *mlx_win, void *mlx_image, unsigned int iter);
void	mandelbrot2(t_data *mlx_data, unsigned int iter);

/* -----------------------------
	fonction pour les user input
   ----------------------------- */
int input_test(int key);
int	esc_key(int key, t_data *mlx_data);
int	user_input(int key, int x, int y, t_data *mlx_data);

#endif