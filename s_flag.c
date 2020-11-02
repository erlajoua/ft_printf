#include "ft_printf.h"
#include <string.h> 

int		is_arga_s(char *str)
{
	while(*str != '.')
		str++;
	str++;
	while(*str != 's')
	{
		if(*str == '*')
			return (1);
		str++;
	}
	return (0);
}


int	ret_null(void)
{
	ft_putstr("(null)");
	return (6);
}

int	s_bneg_apos(int before, int after, va_list args) //
{
	char *str;
	int n;
	int len;
	int nb_sp;
	int ret;
	
	ret = 0;
	nb_sp = 0;
	n = 0;
	before = -before;
	str = va_arg(args, char *);
	if (str)
		len = ft_strlen(str);
	n = (after > len) ? len : after;
	if (after == 0 || n < 0)
		n = 0;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	if (str)
		ft_putstrn(str, n);
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	s_bneg_aneg(int before, va_list args) //
{
	int n;
	int ret;
	int len;
	int nb_sp;
	char *str;

	str = va_arg(args, char *);
	nb_sp = 0;
	len = 0;
	ret = 0;
	n = 0;
	before = -before;
	if (!str && before > 5)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = (before > len) ? len : before;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	if (str)
		ft_putstrn(str, n);
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}
//
int	s_bpos_apos(int before, int after, va_list args) //pas sur testé
{
	char *str;
	int n;
	int len;
	int nb_sp;
	int ret;
	
	ret = 0;
	nb_sp = 0;
	n = 0;
	str = va_arg(args, char *);
	if (str)
		len = ft_strlen(str);
	n = (after > len) ? len : after;
	if (after == 0 || n < 0)
		n = 0;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstrn(str, n);
	return (ret);
}

int	s_bpos_aneg(int before, va_list args) //
{	
	int n;
	int ret;
	int len;
	int nb_sp;
	char *str;

	str = va_arg(args, char *);
	nb_sp = 0;
	len = 0;
	ret = 0;
	n = 0;
	if (!str && before > 5)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = (before > len) ? len : before;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstrn(str, n);
	return (ret);
}

int	tri_arg_s(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
		ret = s_bneg_aneg(before, args);
	else
		ret = s_bpos_aneg(before, args);
	return (ret);
}

int	tri_moins_s(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = get_nbatoi_c(str, 's');
	if (before < 0)
		ret = s_bneg_apos(before, 0, args);
	else
		ret = s_bpos_apos(before, 0, args);
	return (ret);
}

int	tri_before_neg(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = s_bneg_aneg(before, args);
	else
		ret = s_bneg_apos(before, after, args);
	return (ret);
}

int	tri_before_pos(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = s_bpos_aneg(before, args);
	else
		ret = s_bpos_apos(before, after, args);
	return (ret);
}

int	tri_prn_s(char *str, va_list args)
{
	int before;
	int after;
	int ret;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_s(str))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 's');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	//printf("before : %d, after : %d\n", before, after);
	if (before < 0)
		ret = tri_before_neg(before, after, args);
	else
		ret = tri_before_pos(before, after, args);
	return (ret);
}

int	s_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 's'))
		ret = tri_prn_s(str, args);
	else if (is_arg_c(str, 's'))
		ret = tri_arg_s(str, args);
	else
		ret = tri_moins_s(str, args);
	return (ret);
}
