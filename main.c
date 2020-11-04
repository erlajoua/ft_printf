#include "ft_printf.h"

int main(void)
{
	int tab[] = {-135, -12, -1, 0, 1, 13, 198};

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", ft_printf("|%-4.x|", tab[i]));
		printf("%d\n\n", printf("|%-4.x|", tab[i]));
	}
		
	printf("%d\n", ft_printf("|%d|", 42));
	printf("%d\n\n", printf("|%d|", 42));
	
	return (0);

}
