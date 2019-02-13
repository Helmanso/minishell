/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:23:08 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 15:56:34 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*src1;
	char	*dest1;
	size_t	i;

	src1 = (char *)src;
	dest1 = (char *)dest;
	i = 0;
	while (i < count && src1 != dest1)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
