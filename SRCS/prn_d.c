#include "../header/ft_printf.h"

int		get_after_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	while (*str != '.')
		str++;
	str++;
	while(*str != 'd')
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

int		get_before_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	str++;
	while (*str != '.')
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
int		prn_plus_tri(va_list args, int before, int after)
{	
	int ret;

	ret = 0;
	if (before == 0 && after == 0)
		ret = prn_b0_a0(args);
	else if (before > 0 && after == 0)	
		ret = prn_b1_a0(args, before);
	else if (before == 0 && after > 0)
		ret = prn_b0_a1(args, after);
	else if (before > 0 && after > 0)
		ret = prn_b1a1_tri(args, before, after);
	return (ret);
}

int		tri_prn_d(char *str, va_list args)
{
	int before;
	int after;
	int ret;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_d(str))
		after = va_arg(args, int);
	else
		after = get_after_d(str);
//	printf("before %d after %d\n",before,after);
	if (is_moins_prn_d(str, before) == 0) //si y'a un +
	{
		if(before >= 0 && after >= 0)
			ret = prn_plus_tri(args, before, after);
		else
			ret = tri_plus_prn_d(args, before, after);
	}
	else
	{
		if(before >= 0 && after >= 0)
			ret = prn_moins_tri(args, before, after);
		else
			ret = tri_moins_prn_d(args, before, after);
	}
	return (ret);
}

int		is_prn_d(char *str)
{
	while(*str != 'd' && *str)
	{
		if(*str == '.')
			return(1);
		str++;
	}
	return (0);
}
