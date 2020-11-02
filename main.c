#include "ft_printf.h"

int main(void)
{
	printf("%d\n", ft_printf("|%-16s|", ""));
	printf("%d\n", printf("|%-16s|", ""));
	return (0);
}
