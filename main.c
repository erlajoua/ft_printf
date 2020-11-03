#include "ft_printf.h"

int main(void)
{
	int nb = 135;

	printf("%d\n", ft_printf("|%-4.4i|", nb));
	printf("%d\n\n", printf("|%-4.4i|", nb));
		
	
	return (0);

}
