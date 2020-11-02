#include "ft_printf.h"

int	ret_null(void)
{
	ft_putstr("(null)");
	return (6);
}

int	s_bneg_apos(int before, int after, va_list args) //normalement c fait
{
	int ret;
	int nb_sp;
	int len;
	int n;
	char *str;

	len = 0;
	before = (before < 0) ? -before : before;
	str = va_arg(args, char *);
	if (!str && (before > 5 || after > 5))
	{
		str = "(null)";
	}
	else if (!str)
		str = " ";
	if (str)
		len = ft_strlen(str);
	n = (after < len) ? after : len;
	nb_sp = before - n;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = nb_sp + n;
	if (str)
		ft_putstrn(str, n);
	else
		ft_putstr("(null)");
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	s_bneg_aneg(int before, va_list args) //pas fait
{
	int ret;
	int nb_sp;
	int len;
	char *str;
	int n;

	n = 0;
	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	before = (before < 0) ? -before : before;
	nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = nb_sp + len;
	ft_putstr(str);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);

}

//

int	s_bpos_apos(int before, int after, va_list args) //pas fait
{
	int ret;
	int nb_sp;
	int len;
	int n;
	char *str;

	len = 0;
	str = va_arg(args, char *);
	if (!str && (before > 5 || after > 5))
	{
		str = "(null)";
		/*if (before > 5 && after <= 5)
			after = 0;
		else if (after > 5 && before <= 5)
			before = 0;*/
	}
	else if (!str)
		str = "(null)";
	//printf("str : %s\n", str);
	if (str)
		len = ft_strlen(str); //6
	n = (after < len) ? after : len; //1 < 6 so n = 1 
	nb_sp = before - n;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = nb_sp + n;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstrn(str, n);
	return (ret);
}

int	s_bpos_aneg(int before, va_list args) //pas fait
{
	int ret;
	int nb_sp;
	int len;
	char *str;

	len = 0;
	str = va_arg(args, char *);
	if (!str && before == 0)
		return (ret_null());
	else if (!str)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = nb_sp + len;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstr(str);
	return (ret);

}

int	tri_arg_s(char *str, va_list args)
{
	int before;
	int ret;

	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
		ret = s_bneg_aneg(before, args);
	else
		ret = s_bpos_aneg(before, args);
	return (ret);
}

int	tri_moins_s(char *str, va_list args)
{
	int before;
	int ret;

	ret = 0;
	before = get_nbatoi_c(str, 's');
	if (before < 0)
		ret = s_bneg_aneg(before, args);
	else
		ret = s_bpos_aneg(before, args);
	return (ret);
}

int	tri_before_neg(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = s_bneg_aneg(before, args);
	else
		ret = s_bneg_apos(before, after, args);
	return (ret);
}

int	tri_before_pos(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = s_bpos_aneg(before, args);
	else
		ret = s_bpos_apos(before, after, args);
	return (ret);
}

int	tri_prn_s(char *str, va_list args)
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
		after = get_after_c(str, 's');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_before_neg(before, after, args);
	else
		ret = tri_before_pos(before, after, args);
	return (ret);
}

int	s_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 's'))
		ret = tri_prn_s(str, args);
	else if (is_arg_c(str, 's'))
		ret = tri_arg_s(str, args);
	else
		ret = tri_moins_s(str, args);
	return (ret);
}
