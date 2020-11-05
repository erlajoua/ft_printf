#include "ft_printf.h"

void	print_zr(int nb)
{
	while (nb-- > 0)
		ft_putchar('0');
}

void	print_sp(int nb)
{
	while (nb-- > 0)
		ft_putchar(' ');
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr_x(unsigned int nb)
{
	char *basehexa;

	basehexa = "0123456789abcdef";
	if (!nb)
		return ;
	ft_putnbr_x(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}

void	ft_putnbr_xx(unsigned int nb)
{
	char *basehexa;

	basehexa = "0123456789ABCDEF";
	if (!nb)
		return ;
	ft_putnbr_xx(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}
