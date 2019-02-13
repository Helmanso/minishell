/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablemanager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:24:22 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/20 13:56:00 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		deltab(char **tab)
{
	char **cpy;

	if (!tab)
		return (1);
	cpy = tab;
	while (*cpy)
		free(*cpy++);
	free(tab);
	return (1);
}

int		tablescount(char **table)
{
	int	i;

	i = 0;
	while (table[i] != NULL)
		i++;
	return (i);
}

void	ft_tablefree(char **tables)
{
	int i;

	i = 0;
	while (tables[i])
	{
		free(tables[i]);
		i++;
	}
	free(tables);
}
