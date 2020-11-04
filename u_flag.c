#include "ft_printf.h"

//5 fonctions

int	bpos_zero_u(int before, char *str)
{
	int ret;

	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, 'u'))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int	special_zero_u(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	uint_lgth(unsigned int nb)
{
	int ret;

	ret = 0;
	if (nb == 0 || nb == -0)
		return (1);
	while(nb > 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int	plus_u(char *str, va_list args)
{
	int nb;
	int ret;
	unsigned int number;

	number = va_arg(args, unsigned int);
	nb = get_nbatoi_c(str, 'u');
	if (is_zero_before_c(str, 'u'))
		ret = bpos_zero_before_u(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero_u(nb, str);
		else
			ret = bpos_else_u(nb, number);
	}
	return (ret);

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
