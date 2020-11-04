#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	lgt_hex(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	ft_putstrn(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && n-- > 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

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
	{
		return ;
	}
	ft_putnbr_x(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}

void	ft_putnbr_X(unsigned int nb)
{
	char *basehexa;

	basehexa = "0123456789ABCDEF";
	if (!nb)
	{
		return ;
	}
	ft_putnbr_X(nb / 16);
	ft_putchar(basehexa[nb % 16]);
}
