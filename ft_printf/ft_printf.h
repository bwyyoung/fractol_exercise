/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/25 07:29:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define PROGRAM_NAME					"ft_printf"
# define ERR							1
# define OK								0
# define LARGEST_STAR_ARGUMENT			((unsigned int)INT_MAX)
# define DEBUG_MODE						1

typedef char			t_bool;

typedef struct			s_format
{
	const char	*string;
	size_t		location;
	size_t		written;
}						t_format;

typedef struct			s_flags
{
	t_bool		left_justify;
	t_bool		pad_with_zeros;
	t_bool		show_sign;
	t_bool		positive_values_begin_blank;
	t_bool		hashtag;
}						t_flags;

typedef enum			e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z
}						t_length;

typedef enum			e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER
	, INVALID_SPECIFIER
}						t_specifier;

typedef struct			s_conv
{
	t_flags				flags;
	unsigned int		width;
	unsigned int		precision;
	t_bool				precision_set;
	t_length			length;
	t_specifier			specifier;
}						t_conv;

int						ft_printf(const char *format_string, ...);
void					handle_format(t_format *format, va_list args);
int						parse_conv(t_conv *conv
											, va_list args
											, t_format *format);
int						parse_flags(t_conv *conv, t_format *format);
int						parse_width(t_conv *conv
									, va_list args
									, t_format *format);
int						parse_precision(t_conv *conv
										, va_list args
										, t_format *format);
int						parse_length(t_conv *conv
											, t_format *format);
int						parse_specifier(t_conv *conv
											, t_format *format);
int						validate_conv(t_conv *conv
											, t_format *format);
int						validate_flags(t_conv *conv
											, t_format *format);
void					validate_flags_ignored(t_conv *conv
											, t_format *format);
void					print_conv(t_conv *conv
											, va_list args
											, t_format *format);
void					print_normal(t_conv *conv
											, va_list args
											, t_format *format);
void					print_char(t_conv *conv, char argument
											, t_format *format);
void					print_wide_chars(t_conv *conv
											, wchar_t *string, size_t length
											, size_t *written);
void					print_format_error(t_format *format);
const char				*get_current(t_format *format);
intmax_t				get_number_argument(t_length length, va_list args);
uintmax_t				get_unsigned_number_argument(t_length length
														, va_list args);
char					*get_string_decimal(t_conv *conv
											, va_list args);
char					*get_string_string(t_conv *conv
											, va_list args);
char					*get_string_pointer(t_conv *conv
											, va_list args);
char					*get_string_hex(t_conv *conv
											, va_list args);
char					*get_string_octal(t_conv *conv
											, va_list args);
void					add_final_padding(t_conv *conv
											, char **string);
void					add_precision_padding(t_conv *conv
											, char **string);
void					add_invalid_padding(t_conv *conv, t_format *format);

int						parse_length(t_conv *conv, t_format *format);
void					ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor);
void					ft_putstrn(char const *source, size_t max_length);
void					ft_putcharn(char c, size_t number);
void					ft_putcharn_fd(char c, size_t number,
						int file_descriptor);
char					*ft_itoa_large(intmax_t number);
char					*ft_itoa_ularge(uintmax_t number);
int						ft_count_digits_ularge(uintmax_t number);
void					ft_atoi_add_digit_ularge(const char c,
						uintmax_t *number);
void					ft_putnbr_large_fd(intmax_t number,
						int file_descriptor);
void					ft_atoi_add_digit_u(const char c,
						unsigned int *number);
size_t					ft_strlen_wide(const wchar_t *original);
size_t					ft_countchars(char const *haystack, char needle
										, size_t length);
char					*ft_basetoa(uintmax_t number, int base);
void					ft_putstr_literal_fd(char const *source
											, int file_descriptor);
void					ft_strtolower(char *string);
int						ft_count_digits(int number);
void					ft_itoa_write(char *last_digit, uintmax_t number);
#endif
