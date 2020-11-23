/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:48:35 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:36 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_putcharac(char c, int *ret)
{
	write(1, &c, 1);
	*ret = *ret + 1;
}

int		is_sp_before_c(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
