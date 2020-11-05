#include "ft_printf.h"

void	ft_putcharac(char c, int *ret)
{
	write(1, &c, 1);
	*ret = *ret + 1;
}
