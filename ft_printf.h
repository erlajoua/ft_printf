#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	    	ft_printf(const char *format, ...);
int	    	d_flag(char *str, va_list args);
int		    is_arg_c(char *str, char c);
int		    get_before_d(char *str);
int		    int_lgth(int nb);
int		    uint_lgth(unsigned int nb);
int		    is_arga_c(char *str, char c);
int		    is_argb_d(char *str);
void		ft_putchar(char c);
int		    get_after_c(char *str, char c);
int		    is_prn_c(char *str, char c);
void		ft_putnbr(int nb);
void		ft_putnbr_u(unsigned int nb);
void		ft_putnbr_x(unsigned int nb);
void		ft_putnbr_xx(unsigned int nb);
int 		is_moins_before_c(char *str, char c);
int		    bneg_aneg(int before, va_list args);
int		    bneg_apos(int before, int after, va_list args);
int		    tri_before_negative(int before, int after, va_list args);
int	    	tri_before_positive(char *str, int before, int after, va_list args);
int	    	bpos_aneg(int before, va_list args, char c, char *str);
int		    tri_moins_d(char *str, va_list args);
int	    	plus_d(char *str, va_list args);
int	      	get_nbatoi_c(char *str, char c);
int	    	bpos_apos(int before, int after, va_list args);
int	    	bpos_zero(int before, char *str);
int	    	is_zero_before_d(char *str);
int	    	special_zero(int before);
int	    	c_flag(char *str, va_list args);
int		    is_moins_c(char *str, char c);
int		    get_nbatoi_c(char *str, char c);
int		    p_flag(char *str, va_list args);
int		    ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_putstrn(char *str, int n);
int		    s_flag(char *str, va_list args);
int	    	s_bneg_aneg(int before, int after, va_list args);
int	    	s_bneg_apos(int before, int after, va_list args);
int		    s_bpos_aneg(int before, va_list args);
int		    s_bpos_apos(int before, int after, va_list args);
int		    s_bneg(int before, va_list args);
int		    s_bpos(int before, va_list args);
int		    u_flag(char *str, va_list args);
int		    is_zero_before_c(char *str, char c);
char		get_d_or_i(char *str);
int		    x_flag(char *str, va_list args);
int		    X_flag(char *str, va_list args);
int		    lgt_hex(unsigned int nb);
int		    ft_print_nil(int before);
int		    ft_print_memory(int before, unsigned long long str);
int		    tri_prn_s(char *str, va_list args);
int	    	tri_moins_s(char *str, va_list args);
int	    	special_zero_u(int before);
int	    	bpos_zero_u(int before, char *str);
int	    	bpos_else_u(int before, unsigned int nb);
int	    	tri_prn_u(char *str, va_list args);
int	    	tri_moins_u(char *str, va_list args);
int	    	tri_arg_u(char *str, va_list args);
int	    	bpos_zero_before_u(int before, unsigned int nb);
int	    	is_in_string(char c);
int	    	bneg_aneg_u(int nb, va_list args);
int	    	bpos_aneg_u(int before, char *str, char c, va_list args);
int	    	bneg_apos_u(int before, int after, va_list args);
int	    	bpos_apos_u(int before, int after, va_list args);
int	    	special_zero_x(int before);
int	    	bpos_zero_x(int before, char *str);
int	    	tri_prn_x(char *str, va_list args);
int	    	tri_arg_x(char *str, va_list args);
int	    	tri_moins_x(char *str, va_list args);
int	    	plus_x(char *str, va_list args);
int	    	bpos_zero_before_x(int before, unsigned int nb);
int	    	bpos_else_x(int before, unsigned int nb);
int	    	bpos_aneg_x(int before, char *str, char c, va_list args);
int	    	bneg_apos_x(int before, int after, va_list args);
int	    	bpos_apos_x(int before, int after, va_list args);
int	    	bneg_aneg_x(int before, va_list args);
int	    	bpos_else_X(int before, unsigned int nb);
int	    	bpos_aneg_X(int before, char *str, char c, va_list args);
int	    	bneg_apos_X(int before, int after, va_list args);
int	    	bpos_apos_X(int before, int after, va_list args);
int	    	bneg_aneg_X(int before, va_list args);
int	    	tri_prn_X(char *str, va_list args);
int	    	tri_arg_X(char *str, va_list args);
int	    	tri_moins_X(char *str, va_list args);
int	    	plus_X(char *str, va_list args);
int	    	bpos_zero_before_X(int before, unsigned int nb);
int		    tri_prn_d(char *str, va_list args);
int		    tri_arg_d(char *str, va_list args);
int	    	bpos_zero_X(int nb, char *str);
int		    special_zero_X(int before);
int		    lgt_heX(unsigned int nb);

#endif
