#include "../header/ft_printf.h"

int	plus_xx(char *str, va_list args)
{
	int					nb;
	int					ret;
	unsigned int		number;

	number = va_arg(args, unsigned int);
	nb = get_nbatoi_c(str, 'X');
	if (is_zero_before_c(str, 'X'))
		ret = bpos_zero_before_xx(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero_xx(nb, str);
		else
			ret = bpos_else_xx(nb, number);
	}
	return (ret);
}

int	tri_moins_xx(char *str, va_list args)
{
	int ret;
	int nb;

	ret = 0;
	nb = get_nbatoi_c(str, 'X');
	ret = bneg_aneg_xx(nb, args);
	return (ret);
}

int	tri_arg_xx(char *str, va_list args)
{
	int ret;
	int arg;

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg_xx(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, 'X'))
			ret = bpos_aneg_xx(arg, str, '0', args);
		else
			ret = bpos_aneg_xx(arg, str, ' ', args);
	}
	return (ret);
}

int	tri_bneg_xx(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg_xx(before, args);
	else
		ret = bneg_apos_xx(before, after, args);
	return (ret);
}

int	tri_bpos_xx(char *str, int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, 'X'))
			ret = bpos_aneg_xx(before, str, '0', args);
		else
			ret = bpos_aneg_xx(before, str, ' ', args);
	}
	else
	{
		ret = bpos_apos_xx(before, after, args);
	}
	return (ret);
}
