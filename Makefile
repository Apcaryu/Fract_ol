CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c input_fonctions.c complex.c color_converter.c error.c \
mouse_zoom.c init_fractal.c fractal_calculation.c display_fractal.c init.c \
color_change.c color_utils.c ft_atof.c fractol_man.c exit_program.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all : $(NAME) thanks

$(NAME) : $(OBJS)
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

thanks :
	@echo "\033[40m\033[37m\e[1mThanks to:\e[0m"
	@echo "\033[5m\033[43m\033[30m<-----Lucas Triollet----->\033[0m"
	@echo "\033[35mplouf plouf plouf eedy aka Eliot"
	@echo "\033[36mchsimon aka Chistopher"
	@echo "\033[36mCopper Swordsman jgreau aka Jean Yves"
	@echo "\033[35mjgarcia aka Julien"
	@echo "?? aka Adrien"
	@echo "\033[36mmtritsch aka Marie"