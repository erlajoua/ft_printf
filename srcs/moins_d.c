#include "../header/ft_printf.h"

int		get_nbatoi_c(char *str, char c)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	while ((*(str + 1)) == '-')
		str++;
	while (*str != c)
	{
		if (*str == '-')
			moins++;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins == 1)
		return (ret * -1);
	return (ret);
}

char	get_d_or_i(char *str)
{
	while (*str)
	{
		if (*str == 'd')
			return (*str);
		else if (*str == 'i')
			return (*str);
		str++;
	}
	return ('%');
}

int		tri_moins_d(char *str, va_list args)
{
	int		ret;
	int		nb;
	char	c;

	ret = 0;
	c = get_d_or_i(str);
	nb = get_nbatoi_c(str, c);
	ret = bneg_aneg(nb, args);
	return (ret);
}
