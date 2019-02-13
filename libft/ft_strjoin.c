/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:08:01 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/21 15:57:01 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	while (s2[j] != '\0')
	{
		strj[k] = s2[j];
		k++;
		j++;
	}
	strj[k] = '\0';
	return (strj);
}
