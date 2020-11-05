#include "../header/ft_printf.h"

int		bneg_aneg(int before, va_list args)
{
	int nb;
	int len;
	int nb_sp;
	int ret;

	nb = va_arg(args, int);
	len = int_lgth(nb);
	nb_sp = (before * -1) - len;
	if (nb < 0)
		nb_sp--;
	if (nb_sp < 0)
		nb_sp = 0;
	ft_putnbr(nb);
	ret = (nb < 0) ? len + nb_sp + 1 : len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int		bneg_apos(int before, int after, va_list args)
{
	int nb;
	int len;
	int nb_zr;
	int nb_sp;
	int ret;

	nb_zr = 0;
	nb_sp = 0;
	nb = va_arg(args, int);
	if (nb == 0 && after == 0)
		return (special_zero(before));
	len = int_lgth(nb);
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb < 0 ? nb_sp-- : 0;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	nb < 0 ? ft_putchar('-') : 0;
	ret = (nb < 0) ? len + nb_sp + nb_zr + 1 : len + nb_sp + nb_zr;
	print_zr(nb_zr);
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	print_sp(nb_sp);
	return (ret);
}

int		bpos_aneg(int before, va_list args, char c, char *str)
{
	int nb;
	int nb_sp;
	int len;
	int ret;

	nb = va_arg(args, int);
	if (nb == 0)
		return (bpos_zero(before, str));
	len = int_lgth(nb);
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	if (nb < 0)
		nb_sp--;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = (nb < 0) ? len + nb_sp + 1 : len + nb_sp;
	if (c == '0' && nb < 0)
		ft_putchar('-');
	while (nb_sp-- > 0)
		ft_putchar(c);
	if (c == ' ' && nb < 0)
		ft_putchar('-');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	return (ret);
}
