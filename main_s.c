#include "ft_printf.h"

int main(void)
{
//%.09s
	char *str = NULL;
	printf(" <- [%d]\n", ft_printf("|%9.2s|", str));
	printf(" <- [%d]\n\n", printf("|%9.2s|", str));

	printf(" <- [%d]\n", ft_printf("|%.09s|", str));
	printf(" <- [%d]\n\n", printf("|%.09s|", str));

	return (0);
}
