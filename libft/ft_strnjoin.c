/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:33:54 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/07 13:34:14 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoin(size_t n, ...)
{
	size_t	total;
	size_t	i;
	va_list	ap;
	char	*res;
	char	*bufarg[MAXARG];

	va_start(ap, n);
	total = get_args(n, &ap, bufarg);
	va_end(ap);
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	*res = '\0';
	i = 0;
	while (i < n && i < MAXARG)
	{
		ft_strcat(res, bufarg[i]);
		i += 1;
	}
	return (res);
}
