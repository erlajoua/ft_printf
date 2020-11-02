#include "ft_printf.h"

int main(void)
{
	char *str = NULL;
	printf(" <- [%d]\n", ft_printf("|%-16.16s|",  str));
	printf(" <- [%d]\n\n", printf("|%-16.16s|", str));

	return (0);
}
