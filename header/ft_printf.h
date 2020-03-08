#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		d_flag(char *str, va_list args);
int		ft_tri(char *str, va_list args);
int		get_lgth_flag(char *str);
char	find_type(char *str);
int		int_lgth(int nb);
int		is_prn_d(char *str);
int		get_after_d(char *str);
int		get_before_d(char *str);
int		tri_prn_d(char *str, va_list args);
int		prn_b1_a0(va_list args, int before);
int		prn_b0_a0(va_list args);
int		prn_b0_a1(va_list args, int after);
int		prn_b1a1_tri(va_list args, int before, int after);
int		prn_b1a1_2(int before, int nb);
int 	prn_b1a1_3(int nb);
int		prn_b1a1_4(int after, int nb);
int		prn_b1a1_5(int before, int after, int nb);
int		is_argb_d(char *str);
int		is_arga_d(char *str);
int 	is_moins_arg_d(char *str, int arg);
int		is_arg_d(char *str);
int		tri_arg_d(char *str, va_list args);
int		moins_arg_d1(va_list args, int arg);
int		moins_arg_d2(va_list args, int arg);
int		is_moins_d(char *str);
int		moins_d(char *str, va_list args);
int		get_int_moins(char *str);
int 	plus_d(char *str, va_list args);
int		get_int_plus(char *str);
int		is_moins_prn_d(char *str, int before);
int		tri_moins_prn_d(va_list args, int before, int after);
int		zr_then_spaces(va_list args, int before, int after);
int		nb_then_spaces(va_list args, int before);
int		tri_plus_prn_d(va_list args, int before, int after);
int		prn_plus_tri(va_list args, int before, int after);
int		prn_moins_tri(va_list args, int before, int after);
int		spaces_then_nb(va_list args, int before);
int		prn_b2a0(va_list args, int before);
int		prn_b0a2(va_list args);
int		moinsmoins_d(char *str, va_list args);
int		moins_arg_d3(va_list args, int arg);

#endif
