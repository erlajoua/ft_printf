#include "ft_printf.h"

int main(void)
{
	int nb = -44564564;

	printf("%i\n", ft_printf("|%-15.*i|", 7, nb));
	printf("%i\n\n", printf("|%-15.*i|", 7, nb));
	

	printf("%i\n", ft_printf("|%-7.*i|", -9, nb));
	printf("%i\n\n", printf("|%-7.*i|", -9, nb));

	printf("%i\n", ft_printf("|%-7.*i|", -15, nb));
	printf("%i\n\n", printf("|%-7.*i|", -15, nb));
	
	
	return (0);

}
