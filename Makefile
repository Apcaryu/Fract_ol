all : 
	gcc main.c fractal.c input_fonctions.c complex.c color_converter.c minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz