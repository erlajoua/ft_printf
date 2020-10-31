#include "ft_printf.h"

int main(void)
{
	printf(" <- [%d]\n", ft_printf("|%c|", '$'));
	printf(" <- [%d]\n\n", printf("|%c|", '$'));

	return (0);
}
