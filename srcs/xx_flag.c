/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:48:47 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:48 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	bpos_zero_xx(int before, char *str)
{
	int ret;

	ret = before;
	if (before == 0)
		ret = 1;
	if (!is_zero_before_c(str, 'X'))
		while (before-- > 1)
			ft_putchar(' ');
	else
		while (before-- > 1)
			ft_putchar('0');
	ft_putchar('0');
	return (ret);
}

int	bpos_else_xx(int before, unsigned int nb)
{
	int len;
	int nb_sp;
	int nb_zr;
	int ret;

	nb_sp = 0;
	nb_zr = 0;
	len = lgt_hex(nb);
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_xx(nb);
	return (ret);
}

int	special_zero_xx(int before)
{
	int ret;

	if (before < 0)
		before = -before;
	ret = before;
	while (before-- > 0)
		ft_putchar(' ');
	return (ret);
}

int	xx_flag(char *str, va_list args)
{
	int ret;

	ret = 0;
	if (is_prn_c(str, 'X'))
		ret = tri_prn_xx(str, args);
	else if (is_arg_c(str, 'X'))
		ret = tri_arg_xx(str, args);
	else if (is_moins_c(str, 'X'))
		ret = tri_moins_xx(str, args);
	else
		ret = plus_xx(str, args);
	return (ret);
}

int	tri_prn_xx(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 'X'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 'X');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_bneg_xx(before, after, args);
	else
		ret = tri_bpos_xx(str, before, after, args);
	return (ret);
}
