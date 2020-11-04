#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb)
{
	//a refaire pour u_int min
	/*if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}*/
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

void	ft_putnbr_X(unsigned int nb)
{
	char *basehexa;

	basehexa = "0123456789ABCDEF";
	if (!nb)
		return ;
	ft_putnbr_X(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}