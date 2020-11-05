#include "../header/ft_printf.h"

int	get_after_c(char *str, char c)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	while (*str != '.')
		str++;
	str++;
	while (*str != c)
	{
		if (*str == '-')
			moins = 1;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins == 1)
		return (ret * -1);
	return (ret);
}

int	get_before_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	while (*str != '.')
	{
		if (*str == '-')
			moins++;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins > 0)
		return (ret * -1);
	return (ret);
}

int	tri_before_negative(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg(before, args);
	else
		ret = bneg_apos(before, after, args);
	return (ret);
}

int	special_zero(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	tri_before_positive(char *str, int before, int after, va_list args)
{
	int		ret;
	char	c;

	c = get_d_or_i(str);
	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, c))
			ret = bpos_aneg(before, args, '0', str);
		else
			ret = bpos_aneg(before, args, ' ', str);
	}
	else
	{
		ret = bpos_apos(before, after, args);
	}
	return (ret);
}
