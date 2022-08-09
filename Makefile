all : 
	gcc main.c fractal.c input_fonctions.c minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz