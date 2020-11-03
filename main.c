#include "ft_printf.h"

int main(void)
{
	char *str = NULL;
	printf("%d\n", ft_printf("|%-*.16u|", 0, str));
	printf("%d\n\n", printf("|%-*.16u|", 0, str));
	

	printf("%d\n", ft_printf("|%-7.*u|", -9, str));
	printf("%d\n\n", printf("|%-7.*u|", -9, str));

	printf("%d\n", ft_printf("|%-7.*u|", -15, str));
	printf("%d\n\n", printf("|%-7.*u|", -15, str));
	return (0);

}
