#include "../header/ft_printf.h"

int	per_bneg_apos(int before, int after)
{
	int len;
	int nb_sp;
	int ret;

	(void)after;
	nb_sp = 0;
	len = 1;
	if (before < 0)
		before = -before;
	nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	ft_putchar('%');
	print_sp(nb_sp);
	return (ret);
}

int	per_bneg_aneg(int before, int after)
{
	int len;
	int nb_sp;
	int ret;

	(void)after;
	len = 1;
	nb_sp = (before * -1) - len;
	if (nb_sp < 0)
		nb_sp = 0;
	ft_putchar('%');
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	per_bpos_apos(int before, int after, char c)
{
	int len;
	int nb_sp;
	int ret;

	(void)after;
	nb_sp = 0;
	len = 1;
	nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(c);
	ft_putchar('%');
	return (ret);
}

int	per_bpos_aneg(int before, char c, char *str)
{
	int nb_sp;
	int len;
	int ret;

	(void)str;
	len = 1;
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(c);
	ft_putchar('%');
	return (ret);
}
