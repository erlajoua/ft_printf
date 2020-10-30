#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%*d|", 16, -10));
	printf(" <- [%d]\n\n", printf("|%*d|", 16, -10));

	printf(" <- [%d]\n", ft_printf("|%20d|", 2));
	printf(" <- [%d]\n\n", printf("|%20d|", 2));

	printf(" <- [%d]\n", ft_printf("|%-13.5d|", 1));
	printf(" <- [%d]\n\n", printf("|%-13.5d|", 1));

	printf(" <- [%d]\n", ft_printf("|%11.11d|", 13));
	printf(" <- [%d]\n\n", printf("|%11.11d|", 13));

	printf(" <- [%d]\n", ft_printf("|%*d|", -12, 20));
	printf(" <- [%d]\n\n", printf("|%*d|", -12, 20));

	return (0);
}
