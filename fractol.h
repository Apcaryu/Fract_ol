/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:01:13 by apellegr          #+#    #+#             */
/*   Updated: 2022/09/07 13:05:35 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000
# define COLOR_MIN 0xFEFEFE
# define DE_COLOR 0x010101
# include "libft/libft.h"
# include "color.h"
# include "complex.h"
# include "error.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

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
	double		zoom;
}	t_img;

typedef struct s_zc
{
	t_cmplx	z;
	t_cmplx	c;
}	t_zc;

typedef struct s_mouse_pos
{
	int	x_pos;
	int	y_pos;
} t_mouse_pos;

typedef struct s_fractal
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
} t_fractal;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	int		mod;
	t_img	img;
	t_zc	zc;
	t_mouse_pos	mouse_pos;
	t_fractal fractal;
}	t_data;

/* -----------------------------
	fonction pour les fractal 
   ----------------------------- */
void	mandelbrot(void *mlx, void *mlx_win, void *mlx_image, unsigned int iter);
void	mandelbrot2(t_data *mlx_data, unsigned int iter);
void	julia(t_data *mlx_data, unsigned int iter);
int		color_change(t_data *mlx_data);
unsigned int	choose_color(char *pos, int i, int iter);

/* -----------------------------
	fonction pour les user input
   ----------------------------- */
int input_test(int key);
int	esc_key(int key, t_data *mlx_data);
int	user_input(int key, int x, int y, t_data *mlx_data);

void	fractal_type(int argc, char *argv[], t_data *mlx_data);
void	mouse_zoom(t_data *mlx_data);

#endif