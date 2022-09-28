CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c input_fonctions.c complex.c color_converter.c error.c \
mouse_zoom.c init_fractal.c fractal_calculation.c display_fractal.c init.c \
color_change.c color_utils.c ft_atof.c fractol_man.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all : $(OBJS)
	make -C libft/ re
	make -C minilibx-linux/
	@$(CC) $(CFLAGS) $(SRCS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) -c $^

clean :
	make -C libft/ clean
	make -C minilibx-linux/ clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all