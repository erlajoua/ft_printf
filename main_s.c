#include "ft_printf.h"

int main(void)
{
	int nb;
	nb = 4;
	printf(" <- [%d]\n", ft_printf("|%*.p|", 20, &nb));
	printf(" <- [%d]\n\n", printf("|%*.p|", 20, &nb));

	return (0);
}
