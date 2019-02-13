/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:51:03 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 12:51:05 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int numb;
	int sign;

	numb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\r' || *str == '\v' || *str == '\f')
	{
		str += 1;
	}
	if (*str == '+')
	{
		str += 1;
	}
	else if (*str == '-')
	{
		str += 1;
		sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		numb = numb * 10 + (*str - '0');
		str += 1;
	}
	return (sign * numb);
}
