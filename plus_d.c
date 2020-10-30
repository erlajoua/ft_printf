#include "ft_printf.h"

int	bpos_zero(int before)
{
	int ret;

	ret = before;
	while (before-- > 1)
		ft_putchar(' ');
	ft_putchar('0');
	return (ret);
}

int	bpos_else(int before, int nb) //blue GDOC
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


int     plus_d(char *str, va_list args)
{
    int nb;
    int ret;
    int number;

    number = va_arg(args, int);
    nb = get_nbatoi_d(str); //before - et
    if (number == 0)
    	ret = bpos_zero(nb);
    else
	ret = bpos_else(nb, number);
    return (ret);
}
