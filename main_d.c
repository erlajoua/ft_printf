#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%*d|", 17, 5));
	printf(" <- [%d]\n\n", printf("|%*d|", 17, 5));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -17, 9, -4));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -17, 9, -4));

	printf(" <- [%d]\n", ft_printf("|%-*.*d|", -5, -17, 14));
	printf(" <- [%d]\n\n", printf("|%-*.*d|", -5, -17, 14));

	printf(" <- [%d]\n", ft_printf("|%*d|", -7, 9));
	printf(" <- [%d]\n\n", printf("|%*d|", -7, 9));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -12));
	printf(" <- [%d]\n\n", printf("|%-20d|", -12));

	return (0);
}
