#include "ft_printf.h"

int		is_moins_c(char *str, char c)
{
	int i;

	i = 0;
	while(*str != c)
	{
		if(*str == '-')
			i++;
		str++;
	}
	return (i);
}


int		is_arg_c(char *str, char c)
{
	while(*str != c)
	{
		if(*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		is_prn_c(char *str, char c)
{
	while(*str != c && *str)
	{
		if(*str == '.')
			return(1);
		str++;
	}
	return (0);
}

