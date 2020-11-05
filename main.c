#include "ft_printf.h"

int main(void)
{
		printf("%d\n", ft_printf("|%0X|", 42));
		printf("%d\n", ft_printf("|%0x|", 42));
		printf("%d\n", ft_printf("|%0d|", 42));
		printf("%d\n", ft_printf("|%0i|", 42));
		printf("%d\n", ft_printf("|%0c|", 's'));
		printf("%d\n", ft_printf("|%0s|", "salut"));
		
	return (0);

}

