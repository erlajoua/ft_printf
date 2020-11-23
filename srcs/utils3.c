/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:48:33 by erlajoua          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:34 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		is_moins_before_c(char *str, char c)
{
	while (*str != c)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int		is_zero_before_c(char *str, char c)
{
	while (*str != c && !is_in_string(*str))
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int		is_moins_c(char *str, char c)
{
	int i;

	i = 0;
	while (*str != c)
	{
		if (*str == '-')
			i++;
		str++;
	}
	return (i);
}

int		is_arg_c(char *str, char c)
{
	while (*str != c)
	{
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int		is_prn_c(char *str, char c)
{
	while (*str != c && *str)
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}
