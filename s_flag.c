#include "ft_printf.h"

int	tri_arg_s(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
		ret = s_bneg_aneg(before, 0, args);
	else
		ret = s_bpos_aneg(before, args);
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
