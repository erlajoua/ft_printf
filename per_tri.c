#include "ft_printf.h"

int	tri_moins_per(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = get_nbatoi_c(str, '%');
	if (before < 0)
		ret = per_bneg_aneg(before, 0, args);
	else
		ret = per_bpos_aneg(before, args);
	return (ret);
}

int	tri_before_neg_per(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = per_bneg_aneg(before, after, args);
	else
		ret = per_bneg_apos(before, after, args);
	return (ret);
}

int	tri_before_pos_per(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = per_bpos_aneg(before, args);
	else
		ret = per_bpos_apos(before, after, args);
	return (ret);
}

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
		ret = tri_before_pos_per(before, after, args);
	return (ret);
}

