#include "ft_printf.h"

int main(void)
{
//%.09s
	char *str = "abc";
	printf(" <- [%d]\n", ft_printf("|%-2.3s|", NULL));
	printf(" <- [%d]\n\n", printf("|%-2.3s|", NULL));

	printf(" <- [%d]\n", ft_printf("|%.09s|", str));
	printf(" <- [%d]\n\n", printf("|%.09s|", str));

	return (0);
}
