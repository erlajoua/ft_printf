#include "ft_printf.h"

int main(void)
{
	int tab[] = {-2147483648, -12, -1, 0, 1, 13, 456};

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", ft_printf("|%0*.*x|", 2, -4, tab[i]));
		printf("%d\n\n", printf("|%0*.*x|", 2, -4, tab[i]));
	}
		
	return (0);

}

