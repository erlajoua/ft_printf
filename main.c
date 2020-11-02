#include "ft_printf.h"

int main(void)
{
	printf("%d\n", ft_printf("|%-2.*s|", 3, NULL));
	printf("%d\n", printf("|%-2.*s|", 3, NULL));
	return (0);
}
