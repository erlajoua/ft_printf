#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%10.*d|", -7, -16));
	printf(" <- [%d]\n\n", printf("|%10.*d|", -7, -16));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", -19, 16, 15));
	printf(" <- [%d]\n\n", printf("|%*.*d|", -19, 16, 15));

	printf(" <- [%d]\n", ft_printf("|%15.*d|", -5, -13));
	printf(" <- [%d]\n\n", printf("|%15.*d|", -5, -13));

	printf(" <- [%d]\n", ft_printf("|%20d|", -10));
	printf(" <- [%d]\n\n", printf("|%20d|", -10));

	printf(" <- [%d]\n", ft_printf("|%*.12d|", 10, 3));
	printf(" <- [%d]\n\n", printf("|%*.12d|", 10, 3));

	return (0);
}
