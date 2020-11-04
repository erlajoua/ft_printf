#include "ft_printf.h"

int	bpos_zero_X(int before, char *str)
{
	int ret;

	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, 'X'))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int	bpos_else_X(int before, unsigned int nb)
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
	ft_putnbr_xx(nb);
	return (ret);
}

int	special_zero_X(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	X_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'X'))
		ret = tri_prn_X(str, args);
	else if (is_arg_c(str, 'X'))
		ret = tri_arg_X(str, args);
	else if (is_moins_c(str, 'X'))
		ret = tri_moins_X(str, args);
	else
		ret = plus_X(str, args);
	return (ret);
}
