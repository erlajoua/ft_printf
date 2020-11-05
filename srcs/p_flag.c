#include "../header/ft_printf.h"

int	is_prn_p(char *str)
{
	while (*str != 'p')
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}

int	tri_arg_p(char *str, va_list args)
{
	int					before;
	int					ret;
	unsigned long long	nb;

	ret = 0;
	before = va_arg(args, int);
	nb = (unsigned long long)va_arg(args, void *);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (!is_prn_p(str) && !nb)
		ret = ft_print_nil(before);
	else
		ret = ft_print_memory(before, nb);
	return (ret);
}

int	tri_moins_p(char *str, va_list args)
{
	int					before;
	int					ret;
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(args, void *);
	ret = 0;
	before = get_nbatoi_c(str, 'p');
	if (!is_prn_p(str) && !nb)
		ret = ft_print_nil(before);
	else
		ret = ft_print_memory(before, nb);
	return (ret);
}

int	p_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_arg_c(str, 'p'))
		ret = tri_arg_p(str, args);
	else
		ret = tri_moins_p(str, args);
	return (ret);
}
