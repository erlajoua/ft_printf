#include "ft_printf.h"

int		get_after_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	while (*str != '.')
		str++;
	str++;
	while (*str != 'd')
	{
		if (*str == '-')
			moins = 1;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins == 1)
		return (ret * -1);
	return (ret);
}

int		get_before_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
	str++;
	while (*str != '.')
	{
		if (*str == '-')
			moins++;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins > 0)
		return (ret * -1);
	return (ret);
}

int	is_moins_before_c(char *str, char c)
{
	while (*str != c)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int	bneg_apos(int before, int after, va_list args) //rougeGDOC
{
	int nb;
	int len;
	int nb_zr;
	int nb_sp;
	
	nb_zr = 0;
	nb_sp = 0;
	nb = va_arg(args, int);
	//printf("nb : %d\n", nb);
	len = int_lgth(nb);
	//printf("len : %d\n", len);
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	if (nb < 0)
		nb_sp--;
	if (nb_sp < 0)
		nb_sp = 0;
	nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (666);
}

int	bneg_aneg(int before, va_list args) //chcked vertGDOC mais pas le return
{
	int nb;
	int len;
	int nb_spaces;

	nb = va_arg(args, int);
	len = int_lgth(nb);
	nb_spaces = (before * -1 ) - len;
	if (nb < 0)
		nb_spaces--;
	ft_putnbr(nb);
	while (nb_spaces-- > 0)
		ft_putchar(' ');
	return (666);
}

int	tri_before_negative(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg(before, args);
	else
		ret = bneg_apos(before, after, args);
	return (ret);
}

int	bpos_aneg(int before, va_list args) //blackGDOC not return
{
	int nb;
	int nb_sp;
	int len;

	nb = va_arg(args, int);
	len = int_lgth(nb);
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	if (nb < 0)
		nb_sp--;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	return (666);
}

int	bpos_apos(int before, int after, va_list args) //blue GDOC
{
	int nb;
	int len;
	int nb_sp;
	int nb_zr;

	nb_sp = 0;
	nb_zr = 0;
	nb = va_arg(args, int);
	len = int_lgth(nb);
	if (after >= len)
		nb_zr = after - len; 
	if (nb < 0) 
		len++;
	nb_sp = before - (nb_zr + len);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	nb < 0 ? ft_putnbr(-nb) : ft_putnbr(nb);
	return (666);
}

int	tri_before_positive(int before, int after, va_list args)
{
	int ret;
	
	ret = 0;
	if (after < 0)
		ret = bpos_aneg(before, args);
	else
		ret = bpos_apos(before, after, args);
	return (ret);
}

int		tri_prn_d(char *str, va_list args) //PRN ARG MOINs
{
	int before;
	int after;
	int ret;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_d(str))
		after = va_arg(args, int);
	else
		after = get_after_d(str);
	if (is_moins_before_c(str, '.') == 1 && before > 0) 
		before *= -1;
	if (before < 0)
		ret = tri_before_negative(before, after, args);
	else
		ret = tri_before_positive(before, after, args);
	return (ret);
}

int		is_prn_d(char *str)
{
	while(*str != 'd' && *str)
	{
		if(*str == '.')
			return(1);
		str++;
	}
	return (0);
}
