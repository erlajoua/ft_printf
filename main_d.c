#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%-20d|", 0));
	printf(" <- [%d]\n\n", printf("|%-20d|", 0));

	printf(" <- [%d]\n", ft_printf("|%-20d|", -17));
	printf(" <- [%d]\n\n", printf("|%-20d|", -17));

	printf(" <- [%d]\n", ft_printf("|%20d|", 7));
	printf(" <- [%d]\n\n", printf("|%20d|", 7));

	printf(" <- [%d]\n", ft_printf("|%*d|", -14, 0));
	printf(" <- [%d]\n\n", printf("|%*d|", -14, 0));

	printf(" <- [%d]\n", ft_printf("|%-*d|", 0, 11));
	printf(" <- [%d]\n\n", printf("|%-*d|", 0, 11));

	return (0);
}
