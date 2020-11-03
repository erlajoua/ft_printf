#include "ft_printf.h"

int main(void)
{
	unsigned int nb = -44564564;

	printf("%d\n", ft_printf("|%-15.*u|", 7, nb));
	printf("%d\n\n", printf("|%-15.*u|", 7, nb));
	

	printf("%d\n", ft_printf("|%-7.*u|", -9, nb));
	printf("%d\n\n", printf("|%-7.*u|", -9, nb));

	printf("%d\n", ft_printf("|%-7.*u|", -15, nb));
	printf("%d\n\n", printf("|%-7.*u|", -15, nb));
	
	
	return (0);

}
