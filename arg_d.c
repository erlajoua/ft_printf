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

int		is_arga_d(char *str)
{
	while(*str != '.')
		str++;
	str++;
	while(*str != 'd')
	{
		if(*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		is_arg_d(char *str)
{
	while(*str != 'd')
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

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
		ret = bneg_aneg(arg, args);
	else
		ret = bpos_aneg(arg, args, ' ');
	return(ret);
}
