/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:42:35 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 15:51:57 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *ptr;

	ptr = malloc(len);
	ft_memcpy(ptr, src, len);
	ft_memcpy(dst, ptr, len);
	free(ptr);
	return (dst);
}
