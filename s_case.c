#include "ft_printf.h"

int	s_bneg_apos(int before, int after, va_list args) //
{
	char *str;
	int n;
	int len;
	int nb_sp;
	int ret;

	ret = 0;
	nb_sp = 0;
	n = 0;
	len = 0;
	before = -before;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = (after > len) ? len : after;
	if (after == 0 || n < 0)
		n = 0;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	if (str)
		ft_putstrn(str, n);
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	s_bneg_aneg(int before, int after, va_list args)
{
	int n;
	int ret;
	int len;
	int nb_sp;
	char *str;
	(void)after;

	str = va_arg(args, char *);
	nb_sp = 0;
	len = 0;
	ret = 0;
	n = 0;
	before = -before;
	if (!str)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = len;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = nb_sp + n;
	if (str)
		ft_putstrn(str, n);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	s_bpos_apos(int before, int after, va_list args)
{
	char *str;
	int n;
	int len;
	int nb_sp;
	int ret;

	ret = 0;
	nb_sp = 0;
	n = 0;
	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = (after > len) ? len : after;
	if (after == 0 || n < 0)
		n = 0;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstrn(str, n);
	return (ret);
}

int	s_bpos_aneg(int before, va_list args) //
{	
	int n;
	int ret;
	int len;
	int nb_sp;
	char *str;

	str = va_arg(args, char *);
	nb_sp = 0;
	len = 0;
	ret = 0;
	n = 0;
	if (!str)
		str = "(null)";
	if (str)
		len = ft_strlen(str);
	n = len;
	nb_sp = (before - n);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = n + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	if (str)
		ft_putstrn(str, n);
	return (ret);
}
