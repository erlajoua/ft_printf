/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:47:33 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:47:34 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		getlen_addr(unsigned long long addr, int i)
{
	if (!addr)
		return (i);
	i = getlen_addr(addr / 16, i + 1);
	return (i);
}

int		print_addr(unsigned long long addr, int i)
{
	char *basehexa;

	basehexa = "0123456789abcdef";
	if (!addr)
	{
		ft_putchar('0');
		ft_putchar('x');
		return (i);
	}
	i = print_addr(addr / 16, i + 1);
	ft_putchar(basehexa[addr % 16]);
	return (i);
}

int		ft_print_memory(int before, unsigned long long str)
{
	int ret;
	int nb_sp;
	int len;

	ret = (before < 0) ? -before : before;
	if (before < 0)
	{
		ret = print_addr((unsigned long long)str, 0) + 2;
		before = -before;
		nb_sp = before - ret;
		nb_sp = (nb_sp < 0) ? 0 : nb_sp;
		ret += nb_sp;
		print_sp(nb_sp);
	}
	else
	{
		len = getlen_addr((unsigned long long)str, 0) + 2;
		nb_sp = before - len;
		nb_sp = (nb_sp < 0) ? 0 : nb_sp;
		ret = (before < len) ? len : ret;
		print_sp(nb_sp);
		print_addr((unsigned long long)str, 0);
	}
	return (ret);
}

int		ft_print_nil(int before)
{
	int ret;

	if (before < 0)
	{
		before = -before;
		ret = (before > 3) ? before : 3;
		before -= 3;
		ft_putstr("0x0");
		while (before-- > 0)
			ft_putchar(' ');
	}
	else
	{
		ret = (before > 3) ? before : 3;
		before -= 3;
		while (before-- > 0)
			ft_putchar(' ');
		ft_putstr("0x0");
	}
	return (ret);
}
