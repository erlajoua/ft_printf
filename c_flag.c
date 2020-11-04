#include "ft_printf.h"

//5 fonctions

int	c_bneg(int before, va_list args)
{
	int ret;
	int nb_sp;
	char c;

	c = va_arg(args, int);
	if (before < 0)
		before = -before;
	nb_sp = before - 1;
	nb_sp = (nb_sp < 0 ) ? 0 : nb_sp;
	ft_putchar(c);
	ret = (before < 1) ? 1 : before;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	c_bpos(int before, va_list args)
{
	int ret;
	int nb_sp;
	char c;
	
	c = va_arg(args, int);
	if (before < 0)
		before = -before;
	nb_sp = before - 1;
	nb_sp = (nb_sp < 0 ) ? 0 : nb_sp;
	ret = (before < 1) ? 1 : before;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	ft_putchar(c);
	return (ret);
}

int	tri_arg_c(char *str, va_list args)
{
	int before;
	int ret;

	before = va_arg(args, int);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (before < 0)
		ret = c_bneg(before, args);
	else
		ret = c_bpos(before, args);
	return (ret);
}

int	tri_moins_c(char *str, va_list args)
{
	int before;
	int ret;
	
	ret = 0;
	before = get_nbatoi_c(str, 'c');
	if (before < 0)
		ret = c_bneg(before, args);
	else
		ret = c_bpos(before, args);
	return (ret);
}

int		c_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_arg_c(str, 'c'))
		ret = tri_arg_c(str, args);
	else
		ret = tri_moins_c(str, args);
	return (ret);
}
