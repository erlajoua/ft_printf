/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:48:28 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:29 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		bpos_apos_u(int before, int after, va_list args)
{
	unsigned int		nb;
	int					len;
	int					nb_sp;
	int					nb_zr;
	int					ret;

	nb_sp = 0;
	nb_zr = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0 && after == 0)
		return (special_zero_u(before));
	len = uint_lgth(nb);
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	return (ret);
}

int		bpos_aneg_u(int before, char *str, char c, va_list args)
{
	unsigned int		nb;
	int					nb_sp;
	int					len;
	int					ret;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
		return (bpos_zero_u(before, str));
	len = uint_lgth(nb);
	nb_sp = 0;
	if (before >= len)
		nb_sp = before - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(c);
	ft_putnbr_u(nb);
	return (ret);
}

int		bneg_apos_u(int before, int after, va_list args)
{
	unsigned int		nb;
	int					len;
	int					nb_zr;
	int					nb_sp;
	int					ret;

	nb_zr = 0;
	nb_sp = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0 && after == 0)
		return (special_zero(before));
	len = uint_lgth(nb);
	if (before < 0)
		before = -before;
	if (after >= len)
		nb_zr = after - len;
	nb_sp = before - (nb_zr + len);
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ret = len + nb_sp + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int		bneg_aneg_u(int before, va_list args)
{
	unsigned int		nb;
	int					len;
	int					nb_sp;
	int					ret;

	nb = va_arg(args, unsigned int);
	len = uint_lgth(nb);
	nb_sp = (before * -1) - len;
	nb_sp = (nb_sp < 0) ? 0 : nb_sp;
	ft_putnbr_u(nb);
	ret = len + nb_sp;
	while (nb_sp-- > 0)
		ft_putchar(' ');
	return (ret);
}

int		bpos_zero_before_u(int before, unsigned int nb)
{
	int			ret;
	int			nb_zr;
	int			len;

	len = uint_lgth(nb);
	nb_zr = before - len;
	if (nb_zr < 0)
		nb_zr = 0;
	ret = len + nb_zr;
	while (nb_zr-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nb);
	return (ret);
}
