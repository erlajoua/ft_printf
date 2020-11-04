#include "ft_printf.h"

//osef

int main(void)
{
	int tab[] = {0, -12, -1, 0, 1, 13, 456};

	for (int i = 0; i < 1; i++)
	{
		printf("%d\n", ft_printf("|%0X|", tab[i]));
		printf("%d\n\n", printf("|%0X|", tab[i]));
	}
		
	return (0);

}

