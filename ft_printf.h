#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int 	is_moins_arg_d(char *str, int arg);
int		moins_arg_d1(va_list args, int arg);
int		moins_arg_d2(va_list args, int arg);
int		moins_arg_d3(va_list args, int arg);
int		is_prn_c(char *str, char c);
int		tri_prn_d(char *str, va_list args);
int		moins_d(char *str, va_list args);
int		moinsmoins_d(char *str, va_list args);
int		is_arg_c(char *str, char c);
int		get_int_moins(char *str);
void	ft_putchar(char c);
int 	plus_d(char *str, va_list args);
int		d_flag(char *str, va_list args);
int		int_lgth(int nb);
int		uint_lgth(unsigned int nb);
void		ft_putnbr(int nb);
void		ft_putnbr_u(unsigned int nb);
int		zr_then_spaces(va_list args, int before, int after);
int		nb_then_spaces(va_list args, int before);
int		prn_b1_a0(va_list args, int before);
int		prn_b0_a0(va_list args);
int		prn_b0_a1(va_list args, int after);
int		prn_b1a1_tri(va_list args, int before, int after);
int		prn_b1a1_2(int before, int nb);
int 	prn_b1a1_3(int nb);
int		prn_b1a1_4(int after, int nb);
int		prn_b1a1_5(int before, int after, int nb);
int		is_argb_d(char *str);
int		is_arga_c(char *str, char c);
int		spaces_then_nb(va_list args, int before);
int		is_moins_prn_d(char *str, int before);
int		is_moins_d(char *str);
int		prn_b2a0(va_list args, int before);
int		prn_b0a2(va_list args);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_tri(char *str, va_list args);
int		get_lgth_flag(char *str);
char	find_type(char *str);
int		get_after_c(char *str, char c);
int		get_before_d(char *str);
int		tri_arg_d(char *str, va_list args);
int		get_int_plus(char *str);
int		tri_prn_moins(va_list args, int before, int after);
int		tri_prn_plus(va_list args, int before, int after);
int		tri_prn_plusplus(va_list args, int before, int after);
int		tri_prn_moinsmoins(va_list args, int before, int after);

int 		is_moins_before_c(char *str, char c);
int		bneg_aneg(int before, va_list args);
int		bneg_apos(int before, int after, va_list args);
int		tri_before_negative(int before, int after, va_list args);
int		tri_before_positive(char *str, int before, int after, va_list args);
int		bpos_aneg(int before, va_list args, char c, char *str);
int		tri_moins_d(char *str, va_list args);
int		plus_d(char *str, va_list args);
int		get_nbatoi_c(char *str, char c);
int		bpos_apos(int before, int after, va_list args);
int		bpos_zero(int before, char *str);
int		is_zero_before_d(char *str);
int		special_zero(int before);
int		c_flag(char *str, va_list args);
int		is_moins_c(char *str, char c);
int		get_nbatoi_c(char *str, char c);
int		p_flag(char *str, va_list args);
int		ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_putstrn(char *str, int n);
int		s_flag(char *str, va_list args);
int		s_bneg_aneg(int before, int after, va_list args);
int		s_bneg_apos(int before, int after, va_list args);
int		s_bpos_aneg(int before, va_list args);
int		s_bpos_apos(int before, int after, va_list args);
int		s_bneg(int before, va_list args);
int		s_bpos(int before, va_list args);
int		u_flag(char *str, va_list args);
int		is_zero_before_c(char *str, char c);

#endif
