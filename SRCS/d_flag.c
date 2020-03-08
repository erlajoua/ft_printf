#include "../header/ft_printf.h"

int		int_lgth(int nb)
{
	int ret;

	ret = 0;
	if (nb == 0 || nb == -0)
		return (1);
	while(nb > 0 || nb < 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int		d_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if(is_prn_d(str))
		ret = tri_prn_d(str, args);
	else if(is_arg_d(str))
		ret = tri_arg_d(str, args);
	else if(is_moins_d(str) == 1)
		ret = moins_d(str, args);
	else if(is_moins_d(str) == 2)
		ret = moinsmoins_d(str, args);
	else
		ret = plus_d(str, args);
	return (ret); 
}

int		moinsmoins_d(char *str, va_list args)
{
	int nb;
	int nb_spaces;
	int before;
	int i;

	//checked
	nb = va_arg(args, int);
	i = 0;
	before = get_int_moins(str);
	if (before < 0)
		before *= -1;
	nb_spaces = before - int_lgth(nb);
	if (nb < 0)
		nb_spaces--;
	if (nb_spaces < 0)
		nb_spaces = 0;
	ft_putnbr(nb);
	while (i++ < nb_spaces)
		ft_putchar(' ');
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}
