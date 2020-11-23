/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:47:38 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:47:39 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	is_zero_bef(char *str)
{
	while (*str != '.' && *str != '%')
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int	is_zero_per(char *str)
{
	while (*str != '.')
		str++;
	while (*str)
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int	tri_moins_per(char *str, va_list args)
{
	int before;
	int ret;

	(void)args;
	ret = 0;
	before = get_nbatoi_c(str, '%');
	if (before < 0)
	{
		ret = per_bneg_aneg(before, 0);
	}
	else
	{
		if (is_zero_bef(str))
			ret = per_bpos_aneg(before, '0', str);
		else
			ret = per_bpos_aneg(before, ' ', str);
	}
	return (ret);
}

int	tri_before_neg_per(int before, int after, va_list args)
{
	int ret;

	(void)args;
	ret = 0;
	if (after < 0)
		ret = per_bneg_aneg(before, after);
	else
		ret = per_bneg_apos(before, after);
	return (ret);
}

int	tri_before_pos_per(int before, int after, char *str, va_list args)
{
	int ret;

	(void)args;
	ret = 0;
	if (after < 0)
	{
		if (is_zero_bef(str))
			ret = per_bpos_aneg(before, '0', str);
		else
			ret = per_bpos_aneg(before, ' ', str);
	}
	else if (after >= 0 && is_zero_bef(str))
	{
		ret = per_bpos_apos(before, after, '0');
	}
	else if (after >= 0)
	{
		ret = per_bpos_apos(before, after, ' ');
	}
	return (ret);
}
