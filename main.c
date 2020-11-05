#include "ft_printf.h"

int main(void)
{
	printf("-->|%-4.%|<--\n");	
	ft_printf("-->|%-4.%|<--\n");	
	
	printf("-->|%-4.*%|<--\n", -4);	
	ft_printf("-->|%-4.*%|<--\n", -4);	
	
	return 0;
}
