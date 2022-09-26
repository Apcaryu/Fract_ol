CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c input_fonctions.c complex.c color_converter.c error.c \
mouse_zoom.c init_fractal.c fractal_calculation.c display_fractal.c init.c \
color_change.c color_utils.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all : $(OBJS) libft
	@$(CC) $(SRCS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) -c $^

libft :
	make -C libft all

clean :
	rm -f $(OBJS)
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)

re : fclean all