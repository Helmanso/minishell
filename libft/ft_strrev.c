/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:50:31 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 14:50:32 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	holder;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		holder = str[i];
		str[i] = str[j];
		str[j] = holder;
		i++;
		j--;
	}
	return (str);
}
