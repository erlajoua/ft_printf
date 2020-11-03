#include "ft_printf.h"



//tri

int	plus_u(char *str, va_list args)
{
	return (666);
}

int	tri_moins_u(char *str, va_list args)
{
	return (666);
}

int	tri_arg_u(char *str, va_list args)
{
	return (66);
}

int	tri_prn_u(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	//if (is_arg)
}

int	u_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'u'))
		ret = tri_prn_u(str, args);
	else if (is_arg_c(str, 'u'))
		ret = tri_arg_u(str, args);
	else if (is_moins_c(str, 'u'))
		ret = tri_moins_u(str, args);
	else
		ret = plus_u(str, args);
	return (ret);
}
