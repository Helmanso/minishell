/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:50:32 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 12:50:42 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_1;
	unsigned char	*s2_1;

	s1_1 = (unsigned char *)s1;
	s2_1 = (unsigned char *)s2;
	i = 0;
	while (s1_1[i] != '\0' || s2_1[i] != '\0')
	{
		if (s1_1[i] != s2_1[i])
		{
			return (s1_1[i] - s2_1[i]);
		}
		i++;
	}
	return (0);
}
