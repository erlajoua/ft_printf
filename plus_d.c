#include "ft_printf.h"

int     plus_d(char *str, va_list args)
{
    int nb;
    int ret;

    nb = get_nbatoi_d(str); //before - et 
    ret = bpos_apos(nb, 0, args);
    return (ret);
}