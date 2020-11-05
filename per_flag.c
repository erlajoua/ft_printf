#include "ft_printf.h"

int	tri_arg_per(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
		ret = per_bneg_aneg(before, 0);
	else
		ret = per_bpos_aneg(before);
	return (ret);
}

int	percent_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, '%'))
		ret = tri_prn_per(str, args);
	else if (is_arg_c(str, '%'))
		ret = tri_arg_per(str, args);
	else
		ret = tri_moins_per(str, args);
	return (ret);
}
