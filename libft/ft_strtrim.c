/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:28:04 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 14:42:46 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*sc;

	if (!s)
		return (NULL);
	if (!(sc = ft_strdup(s)))
		return (NULL);
	while (*sc == ' ' || *sc == '\n' || *sc == '\t')
		sc++;
	i = ft_strlen(sc) - 1;
	while (sc[i] == ' ' || sc[i] == '\n' || sc[i] == '\t')
		i--;
	sc[++i] = '\0';
	if (!(sc = ft_strdup(sc)))
		return (NULL);
	if (sc)
		return (sc);
	return (NULL);
}
