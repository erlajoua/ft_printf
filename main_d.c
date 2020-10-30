#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%-20d|", 1));
	printf(" <- [%d]\n\n", printf("|%-20d|", 1));

	printf(" <- [%d]\n", ft_printf("|%-*.10d|", -17, 17));
	printf(" <- [%d]\n\n", printf("|%-*.10d|", -17, 17));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -14, -9, -6));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -14, -9, -6));

	printf(" <- [%d]\n", ft_printf("|%.1d|", 20));
	printf(" <- [%d]\n\n", printf("|%.1d|", 20));

	printf(" <- [%d]\n", ft_printf("|%20d|", 20));
	printf(" <- [%d]\n\n", printf("|%20d|", 20));

	printf(" <- [%d]\n", ft_printf("|%3.11d|", -4));
	printf(" <- [%d]\n\n", printf("|%3.11d|", -4));

	printf(" <- [%d]\n", ft_printf("|%1.18d|", -20));
	printf(" <- [%d]\n\n", printf("|%1.18d|", -20));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 4));
	printf(" <- [%d]\n\n", printf("|%-20d|", 4));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -12, 16, 0));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -12, 16, 0));

	printf(" <- [%d]\n", ft_printf("|%12.3d|", 5));
	printf(" <- [%d]\n\n", printf("|%12.3d|", 5));

	printf(" <- [%d]\n", ft_printf("|%-16.12d|", -12));
	printf(" <- [%d]\n\n", printf("|%-16.12d|", -12));

	printf(" <- [%d]\n", ft_printf("|%11.15d|", 6));
	printf(" <- [%d]\n\n", printf("|%11.15d|", 6));

	printf(" <- [%d]\n", ft_printf("|%13.1d|", 20));
	printf(" <- [%d]\n\n", printf("|%13.1d|", 20));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -7, 18));
	printf(" <- [%d]\n\n", printf("|%-*d|", -7, 18));

	printf(" <- [%d]\n", ft_printf("|%-2.*d|", 11, 15));
	printf(" <- [%d]\n\n", printf("|%-2.*d|", 11, 15));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 17));
	printf(" <- [%d]\n\n", printf("|%-20d|", 17));

	printf(" <- [%d]\n", ft_printf("|%*d|", 14, 7));
	printf(" <- [%d]\n\n", printf("|%*d|", 14, 7));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -9, -8));
	printf(" <- [%d]\n\n", printf("|%-*d|", -9, -8));

	printf(" <- [%d]\n", ft_printf("|%20d|", 17));
	printf(" <- [%d]\n\n", printf("|%20d|", 17));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 3));
	printf(" <- [%d]\n\n", printf("|%-20d|", 3));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -17));
	printf(" <- [%d]\n\n", printf("|%-20d|", -17));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -4, -11));
	printf(" <- [%d]\n\n", printf("|%-*d|", -4, -11));

	printf(" <- [%d]\n", ft_printf("|%-*.8d|", 11, -17));
	printf(" <- [%d]\n\n", printf("|%-*.8d|", 11, -17));

	printf(" <- [%d]\n", ft_printf("|%17.*d|", -15, 3));
	printf(" <- [%d]\n\n", printf("|%17.*d|", -15, 3));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -14, -2, 8));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -14, -2, 8));

	return (0);
}
