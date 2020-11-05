#include "ft_printf.h"

int main(void)
{
	ft_printf("-->|%0*%|<--\n", 4);	
	printf("-->|%0*%|<--\n\n", 4);	
	/*
	ft_printf("-->|%02.*%|<--\n",4);	
	printf("-->|%02.*%|<--\n\n", 4);	
	
	ft_printf("-->|%*.0%|<--\n", 2);	
	printf("-->|%*.0%|<--\n\n", 2);	
	*/
	return 0;
}
