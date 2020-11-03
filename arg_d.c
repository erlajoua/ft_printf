#include "ft_printf.h"

int		is_argb_d(char *str)
{
	while(*str != '.')
	{
		if(*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		is_arga_c(char *str, char c)
{
	while(*str != '.')
		str++;
	str++;
	while(*str != c)
	{
		if(*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		tri_arg_d(char *str, va_list args)
{
	int ret;
	int arg;
	char c;

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
	return(ret);
}
