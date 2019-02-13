/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 15:41:31 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/21 16:02:30 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrjoin(char const *s1, char const *s2, int len)
{
	int		i;
	int		j;
	int		k;
	char	*strj;

	i = 0;
	j = 0;
	k = 0;
	if (!malloc(ft_strlen(s1) + ft_strlen(s2) + 1))
		return (NULL);
	strj = (char *)malloc(sizeof(strj) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i] != '\0')
	{
		strj[k] = s1[i];
		k++;
		i++;
	}
	while (s2[j] != '\0' && len--)
	{
		strj[k] = s2[j];
		k++;
		j++;
	}
	strj[k] = '\0';
	return (strj);
}
