/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:48:43 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:45 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	plus_x(char *str, va_list args)
{
	unsigned int		number;
	int					nb;
	int					ret;

	number = va_arg(args, unsigned int);
	nb = get_nbatoi_c(str, 'x');
	if (is_zero_before_c(str, 'x'))
		ret = bpos_zero_before_x(nb, number);
	else
	{
		if (number == 0)
			ret = bpos_zero_x(nb, str);
		else
			ret = bpos_else_x(nb, number);
	}
	return (ret);
}

int	tri_moins_x(char *str, va_list args)
{
	int ret;
	int nb;

	ret = 0;
	nb = get_nbatoi_c(str, 'x');
	ret = bneg_aneg_x(nb, args);
	return (ret);
}

int	tri_bneg_x(int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
		ret = bneg_aneg_x(before, args);
	else
		ret = bneg_apos_x(before, after, args);
	return (ret);
}

int	tri_bpos_x(char *str, int before, int after, va_list args)
{
	int ret;

	ret = 0;
	if (after < 0)
	{
		if (is_zero_before_c(str, 'x'))
			ret = bpos_aneg_x(before, str, '0', args);
		else
			ret = bpos_aneg_x(before, str, ' ', args);
	}
	else
	{
		ret = bpos_apos_x(before, after, args);
	}
	return (ret);
}

int	tri_prn_x(char *str, va_list args)
{
	int ret;
	int before;
	int after;

	ret = 0;
	if (is_argb_d(str))
		before = va_arg(args, int);
	else
		before = get_before_d(str);
	if (is_arga_c(str, 'x'))
		after = va_arg(args, int);
	else
		after = get_after_c(str, 'x');
	if (is_moins_before_c(str, '.') == 1 && before > 0)
		before = -before;
	if (before < 0)
		ret = tri_bneg_x(before, after, args);
	else
		ret = tri_bpos_x(str, before, after, args);
	return (ret);
}
