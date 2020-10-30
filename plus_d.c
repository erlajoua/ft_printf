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

	//nb 198 before 4
	nb_sp = 0;
	nb_zr = 0;
	len = int_lgth(nb); //3
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

int	is_in_string(char c)
{
	char *str;

	str = "123456789";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	is_zero_before_d(char *str)
{
	while (*str != 'd' && !is_in_string(*str))
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int	bpos_zero_before(int before, int nb)
{
	int ret;
	int nb_zr;
	int len;

	len = int_lgth(nb);
	nb_zr = before - len;
	if (nb_zr < 0)
		nb_zr = 0;
	ret = (nb < 0) ? len + nb_zr + 1 : len + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr(nb);
	return (ret);
}

int     plus_d(char *str, va_list args)
{
    int nb;
    int ret;
    int number;

    number = va_arg(args, int);
    nb = get_nbatoi_d(str); //before - et
    if (is_zero_before_d(str))
    	ret = bpos_zero_before(nb, number);
    else
    {
    	if (number == 0)
    		ret = bpos_zero(nb);
    	else
		ret = bpos_else(nb, number);
    }
    return (ret);
}
