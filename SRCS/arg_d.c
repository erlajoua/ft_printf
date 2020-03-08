#include "../header/ft_printf.h"

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
	if(is_moins_arg_d(str, arg) == 1)
		ret = moins_arg_d1(args, arg);
	else if(is_moins_arg_d(str, arg) == 0)
		ret = moins_arg_d2(args, arg);
	else if(is_moins_arg_d(str, arg) == 2)
		ret = moins_arg_d3(args, arg);
	return(ret);
}
