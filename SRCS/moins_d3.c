#include "../header/ft_printf.h"

int		is_moins_prn_d(char *str, int before)
{
	int nb_moins;
	
	nb_moins = 0;
	str++;
	while(*str != '.')
	{
		if(*str == '-')
			nb_moins++;
		str++;
	}
	if(before < 0)
		nb_moins--;
	//printf("nb de moins %d\n",nb_moins);
	return (nb_moins);
}

int		tri_moins_prn_d(va_list args, int before, int after)
{
	int ret;
	
	ret = 0;
	if (before < 0 && after > 0)
		ret = zr_then_spaces(args, before, after);
	else if((before < 0 && after < 0) || (before > 0 && after < 0))
		ret = nb_then_spaces(args, before);
	else if(before < 0 && after == 0)
		ret = prn_b2a0(args, before);
	else if(before == 0 && after < 0)
		ret = prn_b0a2(args);
	return (ret);
}

int		nb_then_spaces(va_list args, int before)
{
	int nb;
	int nb_spaces;
	int i;

	//befoire -3    nb-198
	if(before < 0)
		before *= -1;
	i = 0;
	nb = va_arg(args, int);
	nb_spaces = before - int_lgth(nb);
	if(nb < 0)
		nb_spaces--;
	if(nb_spaces < 0)
		nb_spaces = 0;
	ft_putnbr(nb);
	while(i++ < nb_spaces)
		ft_putchar(' ');
	return (nb < 0)?nb_spaces + int_lgth(nb) + 1:nb_spaces + int_lgth(nb);
}
int		zr_then_spaces(va_list args, int before, int after)
{
	int nb_spaces;
	int nb_zr;
	int nb;
	int nb_cpy;
	int i;

	if(before < 0)
		before *= -1;
	i = 0;
	nb = va_arg(args, int);	
	nb_cpy = nb;
	if (after <= int_lgth(nb))
		nb_spaces = before - int_lgth(nb);
	else
		nb_spaces = before - after;
	if (nb < 0)
	{
		ft_putchar ('-');
		nb *= -1;
		nb_spaces--;
	}
	if (nb_spaces < 0)
		nb_spaces = 0;
	if (after >= int_lgth(nb))
		nb_zr = after - int_lgth(nb);
	else
		nb_zr = 0;
//	if (nb == 0) //PROBLEME avec (-4.*d) et -4   4   0
//		nb_zr--;
	while(i++ < nb_zr)
		ft_putchar('0');
	i = 0;
	ft_putnbr(nb);
	while(i++ < nb_spaces)
		ft_putchar(' ');
	return (nb_cpy < 0)?nb_spaces + nb_zr + int_lgth(nb) + 1:nb_spaces + nb_zr + int_lgth(nb);
}
