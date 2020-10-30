#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%12.9d|", -15));
	printf(" <- [%d]\n\n", printf("|%12.9d|", -15));

	printf(" <- [%d]\n", ft_printf("|%-20d|", 20));
	printf(" <- [%d]\n\n", printf("|%-20d|", 20));

	printf(" <- [%d]\n", ft_printf("|%*.*d|", 16, -4, -17));
	printf(" <- [%d]\n\n", printf("|%*.*d|", 16, -4, -17));

	printf(" <- [%d]\n", ft_printf("|%*.2d|", 19, -2));
	printf(" <- [%d]\n\n", printf("|%*.2d|", 19, -2));

	printf(" <- [%d]\n", ft_printf("|%*d|", 20, -6));
	printf(" <- [%d]\n\n", printf("|%*d|", 20, -6));

	return (0);
}
