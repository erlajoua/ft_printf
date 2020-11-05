#include "ft_printf.h"

int		bpos_apos(int before, int after, va_list args)
{
	int nb;
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	nb = va_arg(args, int);
	if (nb == 0 && after == 0)
		return (special_zero(before));
	len = int_lgth(nb);
	if (after >= len)
		nb_zr = after - len;
	nb < 0 ? len++ : 0;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	return (ret);
}

int		tri_prn_d(char *str, va_list args)
{
	int		before;
	int		after;
	int		ret;
	char	c;

	c = get_d_or_i(str);
	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, c))
		after = va_arg(args, int);
	else
		after = get_after_c(str, c);
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before *= -1;
	if (before < 0)
		ret = tri_before_negative(before, after, args);
	else
		ret = tri_before_positive(str, before, after, args);
	return (ret);
}

int		is_argb_d(char *str)
{
	while (*str != '.')
	{
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		is_arga_c(char *str, char c)
{
	while (*str != '.')
		str++;
	str++;
	while (*str != c)
	{
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		tri_arg_d(char *str, va_list args)
{
	int		ret;
	int		arg;
	char	c;

	c = get_d_or_i(str);
	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, c))
			ret = bpos_aneg(arg, args, '0', str);
		else
			ret = bpos_aneg(arg, args, ' ', str);
	}
	return (ret);
}
