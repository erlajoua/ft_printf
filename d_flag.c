#include "ft_printf.h"

int		int_lgth(int nb)
{
	int ret;

	ret = 0;
	if (nb == 0 || nb == -0)
		return (1);
	while(nb > 0 || nb < 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int		d_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'd') || is_prn_c(str, 'i'))
		ret = tri_prn_d(str, args);
	else if (is_arg_c(str, 'd') || is_arg_c(str, 'i'))
		ret = tri_arg_d(str, args);
	else if (is_moins_c(str, 'd') || is_moins_c(str, 'i'))
		ret = tri_moins_d(str, args);
	else
		ret = plus_d(str, args);
	return (ret); 
}

