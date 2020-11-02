#include "ft_printf.h"

int main(void)
{
	int nb1 = 4;
	printf(" <- [%d]\n", ft_printf("|%-16p|", &nb1));
	printf(" <- [%d]\n\n", printf("|%-16p|", &nb1));

	printf(" <- [%d]\n", ft_printf("|%*.p|", -16, NULL));
	printf(" <- [%d]\n\n", printf("|%*.p|", -16, NULL));
	
	printf(" <- [%d]\n", ft_printf("|%-16.p|", NULL));
	printf(" <- [%d]\n\n", printf("|%-16.p|", NULL));
	return (0);
}
