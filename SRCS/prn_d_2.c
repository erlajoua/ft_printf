#include "../header/ft_printf.h"

int		prn_b0_a0(va_list args)
{
	int nb;
	int ret;

	nb = va_arg(args, int);
	if (nb == 0)
		return (0);
	ft_putnbr(nb);
	ret = int_lgth(nb);
	return (ret);
}

int		prn_b1_a0(va_list args, int before)
{
	int nb_spaces;
	int nb;
	int i;
	
	//checked but not tested
	i = 0;
	nb = va_arg(args, int);
	nb_spaces = before - int_lgth(nb);
	if (nb < 0)
		nb_spaces--;
	if (nb_spaces < 0)
		nb_spaces = 0;
	while(i++ < nb_spaces)
		ft_putchar(' ');
	ft_putnbr(nb);
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		prn_b1a1_tri(va_list args, int before, int after)
{
	int ret;
	int nb;
	int lgt_nb;

	ret = 0;
	nb = va_arg(args, int);	
	lgt_nb = int_lgth(nb);
	if (after <= lgt_nb && after <= before)
		ret = prn_b1a1_2(before, nb);
	else if (after <= lgt_nb && after > before)
		ret = prn_b1a1_3(nb);
	else if (after > lgt_nb && after > before)
		ret = prn_b1a1_4(after, nb);
	else if (after > lgt_nb && after <= before)
		ret = prn_b1a1_5(before, after, nb);
	return (ret);
}

int		prn_b1a1_2(int before, int nb)
{
	int nb_spaces;
	int i;

	i = 0;
	nb_spaces = before - int_lgth(nb);
	if (nb < 0)
		nb_spaces--;
	if (nb_spaces < 0)
		nb_spaces = 0;
	while(i++ < nb_spaces)
		ft_putchar(' ');
	ft_putnbr(nb);
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		prn_b1a1_3(int nb)
{
	ft_putnbr(nb);
	return (int_lgth(nb));
}
