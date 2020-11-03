#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c ,1);
}

char	find_type(char *str)
{
	int i;

	i = 0;
	while(str[i] != 'd' && str[i] != 'i' && str[i] != 'c' && str[i] != 'p' && str[i] != 's' && str[i] != 'u')
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
	int ret;

	ret = 0;
	type_flag = find_type(str);
	if (type_flag == 'd' || type_flag == 'i')
		ret = d_flag(str, args);
	else if (type_flag == 'c')
		ret = c_flag(str, args);
	else if (type_flag == 'p')
		ret = p_flag(str, args);
	else if (type_flag == 's')
		ret = s_flag(str, args);
	else if (type_flag == 'u')
		ret = u_flag(str, args);
	return (ret);
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
			lgt_flag = get_lgth_flag(str);
			str += lgt_flag + 1;
		}
		str++;
	}
	return (ret);
}
