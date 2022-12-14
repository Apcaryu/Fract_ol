/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:01:13 by apellegr          #+#    #+#             */
/*   Updated: 2022/11/11 00:59:45 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000
# include "libft/libft.h"
# include "color.h"
# include "complex.h"
# include "ft_atof.h"
# include "input_macro.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_min_max
{
	double	*min;
	double	*max;
}	t_min_max;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	char	animation_mod;
	t_bool	is_animated;
	int		color_min;
	int		decolor;
}	t_img;

typedef struct s_xy
{
	unsigned int	x;
	unsigned int	y;
}	t_xy;

typedef struct s_zc
{
	t_cmplx	z;
	t_cmplx	c;
}	t_zc;

typedef struct s_mouse_pos
{
	int	x_pos;
	int	y_pos;
}	t_mouse_pos;

typedef struct s_fractal
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		image_x;
	int		image_y;
	double	zoom_x;
	double	zoom_y;
}	t_fractal;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	int			mod;
	int			key;
	t_img		img;
	t_zc		zc;
	t_mouse_pos	mouse_pos;
	t_fractal	fractal;
}	t_data;

/*  ------------------------
	initialization functions
	------------------------ */

void		base_init(t_data *m_data);
void		first_init(t_data *m_data);

/*  -----------------
	fractal functions
	----------------- */

void		fractal_type(int argc, char *argv[], t_data *mlx_data);
t_fractal	init_fractal(t_data *m_data);
void		init_zc(t_data *m_data, t_xy pos_xy, t_fractal fractal);
void		is_in_fractal(t_data m_data, char *pos);
void		is_out_fractal(t_data m_data, char *pos, unsigned int i);
void		mouse_zoom(t_data *m_data);
void		fractal_run(t_data *m_data, unsigned int iter);

/*  ----------------------
	render color functions
	---------------------- */

void		select_change_color(t_data *m_data, t_bool is_right);
void		cut_rgb_canal(t_data *m_data, int key);
int			color_change(t_data *mlx_data);

/*  ---------------------------
	user interactions functions
 	--------------------------- */

void		exit_program(t_data *m_data);
int			win_close(t_data *m_data);
int			key(int key, t_data *mlx_data);
int			user_input(int key, int x, int y, t_data *mlx_data);

/*  ------------------
	Security functions
	------------------ */

void		check_mlx(t_data *m_data, char mod);

/*  --------------
	Help functions
	-------------- */

void		fractol_man(void);

#endif