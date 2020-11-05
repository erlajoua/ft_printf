#include "ft_printf.h"

int	per_bneg_apos(int before, int after)
{
	int len;
	int nb_zr;
	int nb_sp;
	int ret;

	nb_zr = 0;
	nb_sp = 0;
	//if (nb == 0 && after == 0)
	//	return (special_zero(before));
	len = 1;
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	//nb < 0 ? ft_putchar('-') : 0;
	ret = len + nb_sp + nb_zr;
	print_zr(nb_zr);
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
	//if (nb < 0)
	//	nb_sp--;
	if (nb_sp < 0)
		nb_sp = 0;
	ft_putchar('%');
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	per_bpos_apos(int before, int after)
{
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	//if (nb == 0 && after == 0)
	//	return (special_zero(before));
	len = 1;
	if (after >= len)
		nb_zr = after - len;
	//nb < 0 ? len++ : 0;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	//nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putchar('%');
	return (ret);
}

int	per_bpos_aneg(int before)
{
	int nb_sp;
	int len;
	int ret;

	//if (nb == 0)
	//	return (bpos_zero(before, str));
	len = 1;
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	//if (nb < 0)
	//	nb_sp--;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	//if (c == '0' && nb < 0)
	//	ft_putchar('-');
	//while (nb_sp-- > 0)
	//	ft_putchar(c);
	//if (c == ' ' && nb < 0)
	//	ft_putchar('-');
	ft_putchar('%');
	return (ret);
}

