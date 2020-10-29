#include "ft_printf.h"

int main(void)
{
	ft_printf("-->|%11.*d|\n", -9, 15);
	printf("-->|%11.*d|\n\n", -9, 15);

	ft_printf("-->|%-*d|\n", 15, 2);
	printf("-->|%-*d|\n\n", 15, 2);

	ft_printf("-->|%14.*d|\n", 0, -1);
	printf("-->|%14.*d|\n\n", 0, -1);

	ft_printf("-->|%20d|\n", 18);
	printf("-->|%20d|\n\n", 18);

	ft_printf("-->|%-*.*d|\n", 12, -3, 7);
	printf("-->|%-*.*d|\n\n", 12, -3, 7);

	ft_printf("-->|%18.*d|\n", -20, -9);
	printf("-->|%18.*d|\n\n", -20, -9);

	ft_printf("-->|%-*d|\n", 7, 15);
	printf("-->|%-*d|\n\n", 7, 15);

	ft_printf("-->|%-15.17d|\n", 17);
	printf("-->|%-15.17d|\n\n", 17);

	ft_printf("-->|%-11.*d|\n", 2, -2);
	printf("-->|%-11.*d|\n\n", 2, -2);

	return (0);
}
