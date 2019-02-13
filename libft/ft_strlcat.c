/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:48:31 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 15:43:13 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int siz;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j])
		++j;
	if (size <= i)
		j += size;
	else
		j += i;
	siz = 0;
	while (src[siz] && i + 1 < size)
	{
		dest[i] = src[siz];
		siz++;
		i++;
	}
	dest[i] = '\0';
	return (j);
}
