# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	gcc -Wall -Werror -Wdeprecated-declarations -Wextra
CCO		=	gcc -o
LIB		=	-L ft_printf/ -lftprintf -L libft/ -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
FLAGS	=	-Wall -Werror -Wextra

INC		=	libft/includes/ -I ft_printf/

C_FILES	= main.c
C_FILES += get_next_line.c
C_FILES += window.c
C_FILES += ft_split.c
C_FILES += key.c
C_FILES += ft_list_push_back.c
C_FILES += render.c
C_FILES += render_line.c
C_FILES += julia.c
C_FILES += mandelbrot.c
C_FILES += color.c
C_FILES += pixel.c
C_FILES += koch.c
C_FILES += math.c
C_FILES += cohen_suth.c

O_FILES	= main.o
O_FILES += get_next_line.o
O_FILES += window.o
O_FILES += ft_split.o
O_FILES += key.o
O_FILES += ft_list_push_back.o
O_FILES += render.o
O_FILES += render_line.o
O_FILES += julia.o
O_FILES += mandelbrot.o
O_FILES += color.o
O_FILES += pixel.o
O_FILES += koch.o
O_FILES += math.o
O_FILES += cohen_suth.o

all		: $(NAME)

$(NAME)	:
	@make -C libft/
	@make -sC minilibx_macos/
	@make -C ft_printf/
	@$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	@$(CCO) $(NAME) $(O_FILES) $(LIB)

clean	:
	@make -C libft/ clean
	@make -sC minilibx_macos/ clean
	@make -C ft_printf/ clean
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@make -C libft/ fclean
	@make -sC minilibx_macos/ clean
	@make -C ft_printf/ fclean
	@/bin/rm -f $(NAME)

re		: fclean all
