#include "ft_printf.h"

int	getlen_addr(unsigned long long addr, int i)
{
    if (!addr)
        return (i);
    i = getlen_addr(addr / 16, i + 1);
    return (i);
}

int	print_addr(unsigned long long addr, int i)
{
    char *basehexa;

    basehexa = "0123456789abcdef";
    if (!addr)
    {
        ft_putchar('0');
        ft_putchar('x');
        return (i);
    }
    i = print_addr(addr / 16, i + 1);
    ft_putchar(basehexa[addr % 16]);
    return (i);
}
 
int    ft_print_memory(int before, unsigned long long str)
{
    int ret;
    int nb_sp;
    int len;

    ret = 0;
    ret = (before < 0) ? -before : before;
    if (before < 0)
    {
    	ret = print_addr((unsigned long long)str, 0) + 2;
	before = -before;
	nb_sp = before - ret;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret += nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
    }
    else
    {
    	len = getlen_addr((unsigned long long)str, 0) + 2;
	nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = (before < len) ? len : ret; 
    	while (nb_sp-- > 0)
		ft_putchar(' ');
	print_addr((unsigned long long)str, 0);
    }
    return (ret);
}

int	addr_null(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_print_nil(int before)
{
	int ret;
	

	if (before < 0)
	{
		before = -before;
		ret = (before > 5) ? before : 5;
		before -= 5;
		ft_putstr("(nil)");
		while (before-- > 0)
			ft_putchar(' ');
	}
	else
	{
		ret = (before > 5) ? before : 5;
		before -= 5;
		while (before-- > 0)
			ft_putchar(' ');
		ft_putstr("(nil)");
	}
	return (ret);
}

int	tri_arg_p(char *str, va_list args)
{
	int before;
	int ret;
	unsigned long long nb;

	ret = 0;
	before = va_arg(args, int);
	nb = (unsigned long long)va_arg(args, void *);
	if (is_moins_before_c(str, '*') && before > 0)
		before = -before;
	if (!nb)
		ret = ft_print_nil(before);
	else
		ret = ft_print_memory(before, nb);
	return (ret);
}

int	tri_moins_p(char *str, va_list args)
{
	int before;
	int ret;
	unsigned long long nb;

	nb = (unsigned long long)va_arg(args, void *);
	ret = 0;
	before = get_nbatoi_c(str, 'p');
	if (!nb)
		ret = ft_print_nil(before);
	else
		ret = ft_print_memory(before, nb);
	return (ret);
}

int	p_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_arg_c(str, 'p'))
		ret = tri_arg_p(str, args);
	else
		ret = tri_moins_p(str, args);
	return (ret);
}
