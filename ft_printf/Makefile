# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2014/12/10 16:19:13 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
NAME_LIBFT = ../libft/libft.a
CC		=	gcc
CCO		=	gcc -o
LIB		=	-L ../libft/ -lft
ARRC	=	ar rc
RANLIB	=	ranlib
FLAGS	=	-Wall -Werror -Wextra -c

INC		=	../libft/includes/

C_FILES	= ft_printf.c
C_FILES += handle_format.c
C_FILES += parse_conversion.c
C_FILES += parse_flags.c
C_FILES += parse_width.c
C_FILES += parse_precision.c
C_FILES += parse_length.c
C_FILES += parse_specifier.c
C_FILES += validate_conversion.c
C_FILES += validate_flags.c
C_FILES += validate_flags_ignored.c
C_FILES += print_conversion.c
C_FILES += print_normal.c
C_FILES += print_char.c
C_FILES += print_wide_chars.c
C_FILES += print_format_error.c
C_FILES += get_current.c
C_FILES += get_number_argument.c
C_FILES += get_unsigned_number_argument.c
C_FILES += get_string_decimal.c
C_FILES += get_string_string.c
C_FILES += get_string_pointer.c
C_FILES += get_string_octal.c
C_FILES += get_string_hex.c
C_FILES += add_final_padding.c
C_FILES += add_precision_padding.c

C_FILES += ft_itoa_ularge.c
C_FILES += ft_putcharn.c
C_FILES += ft_utils.c
C_FILES += ft_basetoa.c
C_FILES += ft_count_digits.c
C_FILES += printnum.c
C_FILES += ft_strtolower.c

O_FILES	= ft_printf.o
O_FILES += handle_format.o
O_FILES += parse_conversion.o
O_FILES += parse_flags.o
O_FILES += parse_width.o
O_FILES += parse_precision.o
O_FILES += parse_length.o
O_FILES += parse_specifier.o
O_FILES += validate_conversion.o
O_FILES += validate_flags.o
O_FILES += validate_flags_ignored.o
O_FILES += print_conversion.o
O_FILES += print_normal.o
O_FILES += print_char.o
O_FILES += print_wide_chars.o
O_FILES += print_format_error.o
O_FILES += get_current.o
O_FILES += get_number_argument.o
O_FILES += get_unsigned_number_argument.o
O_FILES += get_string_decimal.o
O_FILES += get_string_string.o
O_FILES += get_string_pointer.o
O_FILES += get_string_octal.o
O_FILES += get_string_hex.o
O_FILES += add_final_padding.o
O_FILES += add_precision_padding.o

O_FILES += ft_itoa_ularge.o
O_FILES += ft_putcharn.o
O_FILES += ft_utils.o
O_FILES += ft_basetoa.o
O_FILES += ft_count_digits.o
O_FILES += printnum.o
O_FILES += ft_strtolower.o

all		: $(NAME)

$(NAME)	:
	@$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	@$(ARRC) $(NAME) $(O_FILES) ../libft/*.o
	@$(RANLIB) $(NAME)

clean	:
	@/bin/rm -f $(O_FILES)

fclean	: clean
	@/bin/rm -f $(NAME)

re		: fclean all
