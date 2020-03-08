#include "../header/ft_printf.h"

int		is_moins_d(char *str)
{
	int i;

	i = 0;
	while(*str != 'd')
	{
		if(*str == '-')
			i++;
		str++;
	}
	return (i);
}

int		get_int_moins(char *str)
{
	int ret;

	ret = 0;
	while(*str != '-')
		str++;
	while(*str == '-')
		str++;
	while(*str != 'd')
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret);
}

int		moins_d(char *str, va_list args)
{
	int nb_spaces;
	int i;
	int nb;
	
	//checked but not tested
	nb = va_arg(args, int);
	nb_spaces = get_int_moins(str) - int_lgth(nb);
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

int		plus_d(char *str, va_list args)
{
	int nb_spaces;
	int i;
	int nb;
	int checked_zr;
	int before;
	int nb_zr;
	int nb_cpy;

	before = get_int_plus(str);
	checked_zr = 0;
	i = 0;
	nb = va_arg(args, int);
	//Possibilité de check ce while avant cette fonction pour la rediriger directement plus proprement
	while(*str != ((before % 10) + '0'))
	{
		if(*str == '0')
			checked_zr++;
		str++;
	}
	// Possibilité de faire une autre fonction en cas de 0
	if (checked_zr == 1)
	{
		nb_zr = before - int_lgth(nb);
		nb_cpy = nb;
		if (nb_cpy < 0)
		{
			ft_putchar('-');
			nb *= -1;
			nb_zr--;
		}
		if(nb_zr < 0)
			nb_zr = 0;
		while(i++ < nb_zr)
			ft_putchar('0');
		ft_putnbr(nb);
		return(nb_cpy < 0)?nb_zr + int_lgth(nb) + 1:nb_zr + int_lgth(nb);
	}
	//
	nb_spaces = before - int_lgth(nb);
	if (nb < 0)
		nb_spaces--;
	if (nb_spaces < 0)
		nb_spaces = 0;
	while(i++ < nb_spaces)
		ft_putchar(' ');
	ft_putnbr(nb);
	return(nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}

int		get_int_plus(char *str)
{
	int ret;

	ret = 0;
	str++;
	while(*str != 'd')
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret);
}
