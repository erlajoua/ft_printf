#include "ft_printf.h"

int	plus_X(char *str, va_list args)
{
	int nb;
	int ret;
	unsigned int number;

	number = va_arg(args, unsigned int);
	nb = get_nbatoi_c(str, 'X');
	if (is_zero_before_c(str, 'X'))
		ret = bpos_zero_before_X(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero_X(nb, str);
		else
			ret = bpos_else_X(nb, number);
	}
	return (ret);

}

int	tri_moins_X(char *str, va_list args)
{
	int ret;
	int nb;

	ret = 0;
	nb = get_nbatoi_c(str, 'X'); //before - et 
	ret = bneg_aneg_X(nb, args);
	return (ret);

}

int	tri_arg_X(char *str, va_list args)
{
	int ret;
	int arg;

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg_X(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, 'X'))
			ret = bpos_aneg_X(arg, str, '0', args);
		else
			ret = bpos_aneg_X(arg, str, ' ', args);
	}
	return(ret);

}

int	tri_bneg_X(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg_X(before, args);
	else
		ret = bneg_apos_X(before, after, args);
	return (ret);
}

int	tri_bpos_X(char *str, int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, 'X'))
			ret = bpos_aneg_X(before, str, '0', args);
		else
			ret = bpos_aneg_X(before, str, ' ', args);
	}
	else
	{
		ret = bpos_apos_X(before, after, args);
	}
	return (ret);
}

int	tri_prn_X(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 'X'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 'X');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_bneg_X(before, after, args);
	else
		ret = tri_bpos_X(str, before, after, args);
	return (ret);
}