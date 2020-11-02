#include "ft_printf.h"

int main(void)
{
	char *str = "abc";

	printf(" <- [%d]\n", ft_printf("|%-16.s|", NULL));
	printf(" <- [%d]\n\n", printf("|%-16.s|", NULL));

	return (0);
}
