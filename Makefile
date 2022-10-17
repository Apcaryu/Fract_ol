# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:33:26 by apellegr          #+#    #+#              #
#    Updated: 2022/10/04 13:33:32 by apellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c input_fonctions.c complex.c color_converter.c fractal_setup.c \
mouse_zoom.c init_fractal.c fractal_calculation.c display_fractal.c init.c \
color_change.c color_utils.c ft_atof.c fractol_man.c exit_program.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all : $(NAME) thanks

$(NAME) : $(OBJS)
	@make -C libft/
	@make -C minilibx-linux/
	@$(CC) $(CFLAGS) $(SRCS) libft/libft.a minilibx-linux/libmlx_Linux.a \
	-L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@make -C libft/ clean
	@make -C minilibx-linux/ clean
	@echo "\033[1m\033[32m$(NAME)\033[0m\033[32m program compilated"
	@echo "\033[0m\033[35m\033[11m"

%.o : %.c
	@$(CC) -c $^
	@echo "\033[35m$@ created\033[37m"

clean :
	@make -C libft/ clean
	@make -C minilibx-linux/ clean
	@rm -f $(OBJS)
	@echo "\033[33mobject file of fractol program deleted\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[33m$(NAME) program deleted\033[0m"

re : fclean all

thanks :
	@echo "\033[40m\033[37m\e[1mThanks to:\e[0m"
	@echo "\033[5m\033[43m\033[30m<-----Lucas Triolet----->\033[0m"
	@echo "\033[35mplouf plouf plouf eedy aka Eliot"
	@echo "\033[36mchsimon aka Chistopher"
	@echo "\033[36mCopper Swordsman jgreau aka Jean Yves"
	@echo "\033[35mjgarcia aka Julien"
	@echo "?? aka Adrien"
	@echo "\033[36mmtritsch aka Marie"
