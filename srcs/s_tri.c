#include "../header/ft_printf.h"

int	tri_moins_s(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = get_nbatoi_c(str, 's');
	if (before < 0)
		ret = s_bneg_aneg(before, 0, args);
	else
		ret = s_bpos_aneg(before, args);
	return (ret);
}

int	tri_before_neg(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		ret = s_bneg_aneg(before, after, args);
	}
	else
	{
		ret = s_bneg_apos(before, after, args);
	}
	return (ret);
}

int	tri_before_pos(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = s_bpos_aneg(before, args);
	else
		ret = s_bpos_apos(before, after, args);
	return (ret);
}

int	tri_prn_s(char *str, va_list args)
{
	int before;
	int after;
	int ret;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 's'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 's');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_before_neg(before, after, args);
	else
		ret = tri_before_pos(before, after, args);
	return (ret);
}
