#include "ft_printf.h"

int	bpos_apos_x(int before, int after, va_list args)
{
	unsigned int nb;
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0 && after == 0)
		return (special_zero_x(before));
	len = lgt_hex(nb); //3
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb != 0 ? ft_putnbr_x(nb) : ft_putchar('0');
	return (ret);
}

int	bpos_aneg_x(int before, char *str, char c, va_list args)
{
	unsigned int nb;
	int nb_sp;
	int len;
	int ret;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
		return (bpos_zero_x(before, str)); //je dev
	len = lgt_hex(nb); //3
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(c);
	ft_putnbr_x(nb);
	return (ret);
}

int	bneg_apos_x(int before, int after, va_list args)
{
	unsigned int nb;
	int len;
	int nb_zr;
	int nb_sp;
	int ret;

	nb_zr = 0;
	nb_sp = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0 && after == 0)
		return (special_zero(before));
	len = lgt_hex(nb); //3
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb != 0 ? ft_putnbr_x(nb) : ft_putchar('0');
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	bneg_aneg_x(int before, va_list args)
{
	unsigned int nb;
	int len;
	int nb_sp;
	int ret;

	nb = va_arg(args, unsigned int);
	len = lgt_hex(nb); //3
	//printf("len : %d\n", len);
	nb_sp = (before * -1 ) - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	nb != 0 ? ft_putnbr_x(nb) : ft_putchar('0');
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

//tri

int	bpos_zero_before_x(int before, unsigned int nb)
{
	int ret;
	int nb_zr;
	int len;
	
	len = lgt_hex(nb); //3
	nb_zr = before - len;
	if (nb_zr < 0)
		nb_zr = 0;
	ret = len + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb != 0 ? ft_putnbr_x(nb): ft_putchar('0');
	return (ret);
}

