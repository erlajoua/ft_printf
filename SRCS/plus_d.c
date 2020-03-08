#include "../header/ft_printf.h"

int		prn_b2a0(va_list args, int before)
{
	int nb;
	int nb_spaces;
	int i;
	//ALMOST CHECKED FULL
	if(before < 0)
		before *= -1;
	i = 0;
	nb = va_arg(args, int);
	nb_spaces = before - int_lgth(nb);
	if (nb == 0 || nb == -0)
	{
		while(i++ < nb_spaces + 1)
			ft_putchar(' ');
		return (before);
	}
	if (nb < 0)
		nb_spaces--;
	if (nb_spaces < 0)
		nb_spaces = 0;
	ft_putnbr(nb);
	while(i++ < nb_spaces)
		ft_putchar(' ');
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		spaces_then_nb(va_list args, int before)
{
	int nb_spaces;
	int nb;
	int i;
	
	i = 0;
	nb = va_arg(args, int);
	if (before < 0)
		before *= -1;
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

int		tri_plus_prn_d(va_list args, int before, int after)
{
	int ret;

	ret = 0;
	if (before < 0 && after > 0)
		ret = zr_then_spaces(args, before, after);
	else if(before < 0 && after < 0)
		ret = nb_then_spaces(args, before);
	else if(before > 0 && after < 0)
		ret = spaces_then_nb(args, before);
	else if (before < 0 && after == 0)
		ret = prn_b2a0(args, before);
	return (ret);
}
