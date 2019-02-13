/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:07:07 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 13:33:14 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_dup;

	if (!(s_dup = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (s_dup[i] != '\0')
	{
		s_dup[i] = f(i, s_dup[i]);
		i++;
	}
	return (s_dup);
}
