/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:08:25 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/18 17:18:46 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	vol(int num)
{
	int c;

	c = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = (n < 0) ? 1 : 0;
	len = vol(n);
	if (!(res = ft_strnew(sign + len)))
		return (res);
	if (sign)
		res[0] = '-';
	else if (n > 0)
		len--;
	else
		res[0] = '0';
	while (n)
	{
		if (n > 0)
			res[len] = '0' + (n % 10);
		else
			res[len] = '0' + -(n % 10);
		n = n / 10;
		len--;
	}
	return (res);
}
