/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:57:36 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 13:28:11 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*str;

	if (len == 0)
		return (ptr);
	str = (unsigned char *)ptr;
	while (len--)
	{
		*str = (unsigned char)value;
		if (len)
			str++;
	}
	return (ptr);
}
