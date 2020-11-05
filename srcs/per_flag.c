#include "../header/ft_printf.h"

int	tri_prn_per(char *str, va_list args)
{
	int before;
	int after;
	int ret;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, '%'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, '%');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_before_neg_per(before, after, args);
	else
		ret = tri_before_pos_per(before, after, str, args);
	return (ret);
}

int	tri_arg_per(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
	{
		ret = per_bneg_aneg(before, 0);
	}
	else
	{
		if (is_zero_bef(str))
			ret = per_bpos_aneg(before, '0', str);
		else
			ret = per_bpos_aneg(before, ' ', str);
	}
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
