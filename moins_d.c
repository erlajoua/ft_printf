#include "ft_printf.h"

int		get_nbatoi_c(char *str, char c)
{
	int ret;
	int moins;
	char c_2;

	c_2 = c;
	if (c == 'd')
		c_2 = 'i';
	moins = 0;
	ret = 0;
    	while ((*(str + 1)) == '-')
        	str++;
	while (*str != c && *str != c_2)
	{
		if (*str == '-')
			moins++;
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + *str - '0';
		str++;
	}
	if (moins == 1)
		return (ret * -1);
	return (ret);
}

int tri_moins_d(char *str, va_list args)
{
    int ret;
    int nb;

    ret = 0;
    nb = get_nbatoi_c(str, 'd'); //before - et 
    ret = bneg_aneg(nb, args);
    return (ret);
}
