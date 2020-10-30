#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%.0d|", 0));
	printf(" <- [%d]\n\n", printf("|%.0d|", 0));

	printf(" <- [%d]\n", ft_printf("|%.d|", 0));
	printf(" <- [%d]\n", printf("|%.d|", 0));
	
	printf(" <- [%d]\n", ft_printf("|%5.0d|", 0));
	printf(" <- [%d]\n\n", printf("|%5.0d|", 0));
	
	printf(" <- [%d]\n\n", ft_printf("|%-5.d|", 0));
	printf(" <- [%d]\n\n", printf("|%-5.d|", 0));
	
	printf(" <- [%d]\n\n", ft_printf("|%-5.0d|", 0));
	printf(" <- [%d]\n\n", printf("|%-5.0d|", 0));
	
	printf(" <- [%d]\n\n", ft_printf("|%0.5d|", 0));
	printf(" <- [%d]\n\n", printf("|%0.5d|", 0));
	return (0);
}
