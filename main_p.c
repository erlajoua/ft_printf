#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%p|", 0));
	printf(" <- [%d]\n\n", printf("|%p|", 0));

	return (0);
}
