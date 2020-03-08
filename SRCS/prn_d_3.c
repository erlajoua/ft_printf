#include "../header/ft_printf.h"

int		prn_b1a1_4(int after, int nb)
{
	int nb_zr;
	int i;

	//NEED A CHECKUP
	nb_zr = after - int_lgth(nb);
	i = 0;
	while(i++ < nb_zr)
		ft_putchar('0');
	ft_putnbr(nb);
	return (nb_zr + int_lgth(nb));
}

int		prn_b1a1_5(int before, int after, int nb)
{
	int nb_zr;
	int nb_spaces;
	int i;
	int nb_cpy;
	//NEED A CHECKUP
	//12   8   -198
	nb_cpy = nb;
	nb_zr = after - int_lgth(nb);
	nb_spaces = before - (nb_zr + int_lgth(nb));
	if(nb_cpy < 0)
	{
		nb *= -1;
		nb_spaces--;
	}
	if (nb_spaces < 0)
		nb_spaces = 0;
	i = 0;
	while(i++ < nb_spaces)
		ft_putchar(' ');
	nb_cpy < 0?ft_putchar('-'):i++;
	i = 0;
	while(i++ < nb_zr)
		ft_putchar('0');
	ft_putnbr(nb);
	return (nb_cpy < 0)?nb_spaces + nb_zr + int_lgth(nb) + 1:nb_spaces + nb_zr + int_lgth(nb);
}

int		prn_b0_a1(va_list args, int after)
{
	int nb_zr;
	int nb;
	int i;

	//NEED A CHECKUP TOO
	nb = va_arg(args, int);
	nb_zr = after - int_lgth(nb);
	i = 0;
	while(i++ < nb_zr)
		ft_putchar('0');
	ft_putnbr(nb);
	return (nb_zr + int_lgth(nb));
}
