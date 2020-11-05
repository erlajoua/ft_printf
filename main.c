#include "ft_printf.h"

int main(void)
{
	printf("-->|%-4.%|<--\n");	
	printf("-->|%-4.*%|<--\n", -4);	
	printf("-->|%-4.*%|<--\n", -3);	
	printf("-->|%-4.*%|<--\n", -2);	
	printf("-->|%-4.*%|<--\n", -1);	
	printf("-->|%-4.*%|<--\n", 0);	
	printf("-->|%-4.*%|<--\n", 1);	
	printf("-->|%-4.*%|<--\n", 2);	
	return 0;
}
