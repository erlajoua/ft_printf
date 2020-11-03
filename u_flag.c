#include "ft_printf.h"
//plus_u

int	bpos_zero_u(int before, char *str)
{
	int ret;

	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, 'u'))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int	bpos_else_u(int before, unsigned int nb) //blue GDOC
{
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	len = uint_lgth(nb); //3
	//	if (nb < 0)
	//		len++;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	//	nb < 0 ? ft_putchar('-') : 0;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	return (ret);
}



//utils
//a remove car deja dans prn_d
int	special_zero_u(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	uint_lgth(unsigned int nb)
{
	int ret;

	ret = 0;
	if (nb == 0 || nb == -0)
		return (1);
	while(nb > 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}


//alls b_p

int	bpos_apos_u(int before, int after, va_list args)
{
	unsigned int nb;
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	nb = va_arg(args, unsigned int);
	//printf("\n U_INT : %u\n", nb);
	if (nb == 0 && after == 0)
		return (special_zero_u(before));
	len = uint_lgth(nb);
	if (after >= len)
		nb_zr = after - len;
	//condition negative
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	return (ret);
}

int	bpos_aneg_u(int before, char *str, char c, va_list args)
{
	unsigned int nb;
	int nb_sp;
	int len;
	int ret;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
		return (bpos_zero(before, str)); //je dev
	len = uint_lgth(nb); //2
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	//if (nb < 0)
	//	nb_sp--;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	//if (c == '0' && nb < 0)
	//	ft_putchar('-');
	while (nb_sp-- > 0)
		ft_putchar(c);
	//if (c == ' ' && nb < 0)
	//	ft_putchar('-');
	ft_putnbr_u(nb);
	return (ret);
}

int	bneg_apos_u(int before, int after, va_list args)
{
	unsigned int nb;
	int len;
	int nb_zr;
	int nb_sp;
	int ret;

	nb_zr = 0;
	nb_sp = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0 && after == 0)
		return (special_zero(before));
	len = uint_lgth(nb);
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	//if (nb < 0)
	//	nb_sp--;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	//nb < 0 ? ft_putchar('-') : 0;
	ret = len + nb_sp + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	bneg_aneg_u(int before, va_list args)
{
	unsigned int nb;
	int len;
	int nb_sp;
	int ret;

	nb = va_arg(args, unsigned int);
	len = uint_lgth(nb);
	nb_sp = (before * -1 ) - len;
	//if (nb < 0)
	//	nb_sp--;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ft_putnbr_u(nb);
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

//tri

int	bpos_zero_before_u(int before, unsigned int nb)
{
	int ret;
	int nb_zr;
	int len;

	len = uint_lgth(nb);
	nb_zr = before - len;
	/*if (nb < 0)
	  {
	  ft_putchar('-');
	  nb_zr--;
	  }*/
	if (nb_zr < 0)
		nb_zr = 0;
	ret = len + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	return (ret);
}


int	plus_u(char *str, va_list args)
{
	int nb;
	int ret;
	unsigned int number;

	number = va_arg(args, unsigned int);
	nb = get_nbatoi_c(str, 'u');
	if (is_zero_before_c(str, 'u'))
		ret = bpos_zero_before_u(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero_u(nb, str);
		else
			ret = bpos_else_u(nb, number);
	}
	return (ret);

}

int	tri_moins_u(char *str, va_list args)
{
	int ret;
	int nb;

	ret = 0;
	nb = get_nbatoi_c(str, 'u'); //before - et 
	ret = bneg_aneg_u(nb, args);
	return (ret);

}

int	tri_arg_u(char *str, va_list args)
{
	int ret;
	int arg;

	ret = 0;
	arg = va_arg(args, int);
	if (is_moins_before_c(str, '*') == 1 && arg > 0)
		arg *= -1;
	if (arg < 0)
	{
		ret = bneg_aneg_u(arg, args);
	}
	else
	{
		if (is_zero_before_c(str, 'u'))
			ret = bpos_aneg_u(arg, str, '0', args);
		else
			ret = bpos_aneg_u(arg, str, ' ', args);
	}
	return(ret);

}

//tri prn

int	tri_bneg_u(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg_u(before, args);
	else
		ret = bneg_apos_u(before, after, args);
	return (ret);
}

int	tri_bpos_u(char *str, int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, 'u'))
			ret = bpos_aneg_u(before, str, '0', args);
		else
			ret = bpos_aneg_u(before, str, ' ', args);
	}
	else
	{
		ret = bpos_apos_u(before, after, args);
	}
	return (ret);
}

//

int	tri_prn_u(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 'u'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 'u');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_bneg_u(before, after, args);
	else
		ret = tri_bpos_u(str, before, after, args);
	return (ret);
}

int	u_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'u'))
		ret = tri_prn_u(str, args);
	else if (is_arg_c(str, 'u'))
		ret = tri_arg_u(str, args);
	else if (is_moins_c(str, 'u'))
		ret = tri_moins_u(str, args);
	else
		ret = plus_u(str, args);
	return (ret);
}
