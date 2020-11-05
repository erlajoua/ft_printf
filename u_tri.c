#include "ft_printf.h"

int	tri_moins_u(char *str, va_list args)
{
	int ret;
	int nb;

	ret = 0;
	nb = get_nbatoi_c(str, 'u');
	ret = bneg_aneg_u(nb, args);
	return (ret);
}

int	tri_arg_u(char *str, va_list args)
{
	int ret;
	int arg;

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg_u(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, 'u'))
			ret = bpos_aneg_u(arg, str, '0', args);
		else
			ret = bpos_aneg_u(arg, str, ' ', args);
	}
	return (ret);
}

int	tri_bneg_u(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg_u(before, args);
	else
		ret = bneg_apos_u(before, after, args);
	return (ret);
}

int	tri_bpos_u(char *str, int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, 'u'))
			ret = bpos_aneg_u(before, str, '0', args);
		else
			ret = bpos_aneg_u(before, str, ' ', args);
	}
	else
	{
		ret = bpos_apos_u(before, after, args);
	}
	return (ret);
}

int	tri_prn_u(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 'u'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 'u');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_bneg_u(before, after, args);
	else
		ret = tri_bpos_u(str, before, after, args);
	return (ret);
}
