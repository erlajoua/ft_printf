#include "ft_printf.h"

int main(void)
{
	int tab[] = {-135, -12, -1, 0, 1, 13, 198};

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", ft_printf("|%-4.d|", tab[i]));
		printf("%d\n\n", printf("|%-4.d|", tab[i]));
	}
		
	
	return (0);

}
