#include "header/ft_printf.h"
#include "SRCS/ft_functions.c"
#include "SRCS/d_flag.c"
#include "SRCS/prn_d.c"
#include "SRCS/prn_d_2.c"
#include "SRCS/prn_d_3.c"
#include "SRCS/arg_d.c"
#include "SRCS/moins_d.c"
#include "SRCS/moins_d2.c"
#include "SRCS/moins_d3.c"
#include "SRCS/moins_d4.c"
#include "SRCS/plus_d.c"

char	find_type(char *str)
{
	int i;

	i = 0;
	while(str[i] != 'd')
		i++;
	return (str[i]);
}

int		get_lgth_flag(char *str)
{
	int i;
	char type_flag;

	i = 0;
	type_flag = find_type(str);
	while(str[i] != type_flag && str[i])
		i++;
	i--;
	return (i);
}

int		ft_tri(char *str, va_list args)
{
	char type_flag;
	int nb;

	nb = 0;
	type_flag = find_type(str);
	//printf("type de flag en sortie : %c\n",type_flag);
	if (type_flag == 'd')
		nb = d_flag(str, args);
	return (nb);
}

int		ft_printf(const char *format, ...)
{
	char *str;	
	va_list args;
	int ret;
	int lgt_flag;

	ret = 0;
	va_start(args, format);	
	str = (char *)format;
	while(*str)
	{
		if(*str != '%')
		{
			ft_putchar(*str);
			ret++;
		}
		else if(*str == '%' && *(str + 1) == '%')
		{
			ret++;
			str++;
			ft_putchar('%');
		}
		else
		{
			ret += ft_tri(str, args);
			//printf("ret de sortie : %d\n",ret);
			lgt_flag = get_lgth_flag(str);
			//printf("lgt_flag de sortie : %d\n",lgt_flag);
			str += lgt_flag + 1;
		}
		str++;
	}
	return (ret);
}

int main(void)
{
	printf(" ->[%d]\n", printf("|%-3.*d|", -4, -0));
	printf(" ->[%d]\n", ft_printf("|%-3.*d|", -4, -0));
	return (0);
}
