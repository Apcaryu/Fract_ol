all : libft
	gcc main.c fractal.c input_fonctions.c complex.c color_converter.c error.c libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz

libft :
	gcc -C libft all