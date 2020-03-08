#include "../header/ft_printf.h"

int		prn_b0a2(va_list args)
{
	int nb;
	
	//need check
	nb = va_arg(args, int);
	ft_putnbr(nb);
	return (int_lgth(nb));
}

int		prn_moins_tri(va_list args, int before, int after)
{
	int ret;

	ret = 0;
	if (before == 0 && after == 0)
		ret = prn_b0_a0(args);
	else if(before > 0 && after == 0)
		ret = nb_then_spaces(args, before);
	else if(before == 0 && after > 0)
		ret = prn_b0_a1(args, after);
	else if(before > 0 && after > 0)
		ret = zr_then_spaces(args, before, after);
	return (ret);
}
