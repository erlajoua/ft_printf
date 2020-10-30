#include "ft_printf.h"

int		is_moins_d(char *str)
{
	int i;

	i = 0;
	while(*str != 'd')
	{
		if(*str == '-')
			i++;
		str++;
	}
	return (i);
}

int		get_nbatoi_d(char *str)
{
	int ret;
	int moins;

	moins = 0;
	ret = 0;
    	while ((*(str + 1)) == '-')
        	str++;
	while (*str != 'd')
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
    nb = get_nbatoi_d(str); //before - et 
    ret = bneg_aneg(nb, args);
    return (ret);
}
