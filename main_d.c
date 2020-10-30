#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%0*.*d|", 2, -4, 0));
	printf(" <- [%d]\n\n", printf("|%0*.*d|", 2, -4, 0));

	printf(" <- [%d]\n", ft_printf("|%04.*d|", -2, 0));
	printf(" <- [%d]\n\n", printf("|%04.*d|", -2, 0));
	return (0);
}
