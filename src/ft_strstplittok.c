/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstplittok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:32:21 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/13 14:32:40 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lsh_split_line(char *line)
{
	int		bufsize;
	int		position;
	char	**tokens;
	char	*token;

	bufsize = LSH_TOK_BUFSIZE;
	tokens = malloc(sizeof(char*) * bufsize);
	position = 0;
	token = ft_strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = malloc(sizeof(char*) * bufsize);
		}
		token = ft_strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
