#include "../header/ft_printf.h"

int		bpos_zero(int before, char *str)
{
	int		ret;
	char	c;

	c = get_d_or_i(str);
	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, c))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int		bpos_else(int before, int nb)
{
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	len = int_lgth(nb);
	if (nb < 0)
		len++;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	return (ret);
}

int		is_in_string(char c)
{
	char *str;

	str = "123456789";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int		bpos_zero_before(int before, int nb)
{
	int ret;
	int nb_zr;
	int len;

	len = int_lgth(nb);
	nb_zr = before - len;
	if (nb < 0)
	{
		ft_putchar('-');
		nb_zr--;
	}
	if (nb_zr < 0)
		nb_zr = 0;
	ret = (nb < 0) ? len + nb_zr + 1 : len + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	return (ret);
}

int		plus_d(char *str, va_list args)
{
	int		nb;
	int		ret;
	int		number;
	char	c;

	number = va_arg(args, int);
	c = get_d_or_i(str);
	nb = get_nbatoi_c(str, c);
	if (is_zero_before_c(str, c))
		ret = bpos_zero_before(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero(nb, str);
		else
			ret = bpos_else(nb, number);
	}
	return (ret);
}
