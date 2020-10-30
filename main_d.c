#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%0*.*d|", 4,-4,-12)); //et -3 aussi
	printf(" <- [%d]\n\n", printf("|%0*.*d|", 4, -4,-12));

	printf(" <- [%d]\n", ft_printf("|%04.*d|", -2, -4));
	printf(" <- [%d]\n\n", printf("|%04.*d|", -2, -4));
	
	printf(" <- [%d]\n", ft_printf("|%.*d|", -4, 0));
	printf(" <- [%d]\n\n", printf("|%.*d|", -4, 0));
	return (0);
}
