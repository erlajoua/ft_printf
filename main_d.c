#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%*d|", -3, 16));
	printf(" <- [%d]\n\n", printf("|%*d|", -3, 16));

	printf(" <- [%d]\n", ft_printf("|%-19.*d|", -20, -18));
	printf(" <- [%d]\n\n", printf("|%-19.*d|", -20, -18));

	printf(" <- [%d]\n", ft_printf("|%13.*d|", 13, -4));
	printf(" <- [%d]\n\n", printf("|%13.*d|", 13, -4));

	printf(" <- [%d]\n", ft_printf("|%13.20d|", -1));
	printf(" <- [%d]\n\n", printf("|%13.20d|", -1));

	printf(" <- [%d]\n", ft_printf("|%*d|", 2, 12));
	printf(" <- [%d]\n\n", printf("|%*d|", 2, 12));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 13));
	printf(" <- [%d]\n\n", printf("|%-20d|", 13));

	printf(" <- [%d]\n", ft_printf("|%*d|", -10, 12));
	printf(" <- [%d]\n\n", printf("|%*d|", -10, 12));

	printf(" <- [%d]\n", ft_printf("|%-4.9d|", 6));
	printf(" <- [%d]\n\n", printf("|%-4.9d|", 6));

	printf(" <- [%d]\n", ft_printf("|%-16.20d|", 14));
	printf(" <- [%d]\n\n", printf("|%-16.20d|", 14));

	printf(" <- [%d]\n", ft_printf("|%-7.*d|", 3, -1));
	printf(" <- [%d]\n\n", printf("|%-7.*d|", 3, -1));

	printf(" <- [%d]\n", ft_printf("|%*.8d|", -19, 15));
	printf(" <- [%d]\n\n", printf("|%*.8d|", -19, 15));

	printf(" <- [%d]\n", ft_printf("|%-*.0d|", 4, -5));
	printf(" <- [%d]\n\n", printf("|%-*.0d|", 4, -5));

	printf(" <- [%d]\n", ft_printf("|%20d|", -10));
	printf(" <- [%d]\n\n", printf("|%20d|", -10));

	printf(" <- [%d]\n", ft_printf("|%20d|", -15));
	printf(" <- [%d]\n\n", printf("|%20d|", -15));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 16, -16));
	printf(" <- [%d]\n\n", printf("|%-*d|", 16, -16));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -9, 0));
	printf(" <- [%d]\n\n", printf("|%-*d|", -9, 0));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -15, 5, -17));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -15, 5, -17));

	printf(" <- [%d]\n", ft_printf("|%-16.8d|", -15));
	printf(" <- [%d]\n\n", printf("|%-16.8d|", -15));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 17, 1));
	printf(" <- [%d]\n\n", printf("|%-*d|", 17, 1));

	printf(" <- [%d]\n", ft_printf("|%-*d|", -16, 2));
	printf(" <- [%d]\n\n", printf("|%-*d|", -16, 2));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -2));
	printf(" <- [%d]\n\n", printf("|%-20d|", -2));

	printf(" <- [%d]\n", ft_printf("|%20d|", -1));
	printf(" <- [%d]\n\n", printf("|%20d|", -1));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -14, 5, 11));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -14, 5, 11));

	printf(" <- [%d]\n", ft_printf("|%*d|", -10, -14));
	printf(" <- [%d]\n\n", printf("|%*d|", -10, -14));

	printf(" <- [%d]\n", ft_printf("|%20d|", -9));
	printf(" <- [%d]\n\n", printf("|%20d|", -9));

	return (0);
}
