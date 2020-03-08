#include "../header/ft_printf.h"

int		is_moins_arg_d(char *str, int arg)
{
	int nb_moins;

	nb_moins = 0;
	while(*str != 'd')
	{
		if(*str == '-')
			nb_moins++;
		str++;
	}
	return (arg < 0)?nb_moins + 1:nb_moins;
}

int		moins_arg_d1(va_list args, int arg)
{
	int nb_spaces;
	int nb;
	int i;

	//almost checked
	if (arg < 0)
		arg *= -1;
	nb = va_arg(args, int);
	nb_spaces = arg - int_lgth(nb);
	if (nb < 0)
		nb_spaces--;
	if(nb_spaces < 0)
		nb_spaces = 0;
	i = 0;
	ft_putnbr(nb);
	while(i++ < nb_spaces)
		ft_putchar(' ');
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		moins_arg_d2(va_list args, int arg)
{
	int nb_spaces;
	int nb;
	int i;

	//normally checked
	if (arg < 0)
		arg *= -1;
	nb = va_arg(args, int);
	nb_spaces = arg - int_lgth(nb);
	if (nb < 0)
		nb_spaces --;
	if (nb_spaces < 0)
		nb_spaces = 0;
	i = 0;
	while(i++ < nb_spaces)
		ft_putchar(' ');
	ft_putnbr(nb);
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		moins_arg_d3(va_list args, int arg)
{
	int nb_spaces;
	int nb;
	int i;

	//normally checked
	if (arg < 0)
		arg *= -1;
	nb = va_arg(args, int);
	nb_spaces = arg - int_lgth(nb);
	if (nb < 0)
		nb_spaces --;
	if (nb_spaces < 0)
		nb_spaces = 0;
	i = 0;
	ft_putnbr(nb);
	while(i++ < nb_spaces)
		ft_putchar(' ');
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}
