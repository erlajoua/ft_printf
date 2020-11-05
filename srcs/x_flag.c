#include "ft_printf.h"

int	bpos_zero_x(int before, char *str)
{
	int ret;

	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, 'x'))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int	bpos_else_x(int before, unsigned int nb)
{
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	len = lgt_hex(nb);
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_x(nb);
	return (ret);
}

int	special_zero_x(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	x_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'x'))
		ret = tri_prn_x(str, args);
	else if (is_arg_c(str, 'x'))
		ret = tri_arg_x(str, args);
	else if (is_moins_c(str, 'x'))
		ret = tri_moins_x(str, args);
	else
		ret = plus_x(str, args);
	return (ret);
}

int	tri_arg_x(char *str, va_list args)
{
	int ret;
	int arg;

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg_x(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, 'x'))
			ret = bpos_aneg_x(arg, str, '0', args);
		else
			ret = bpos_aneg_x(arg, str, ' ', args);
	}
	return (ret);
}
