/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:32:53 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/13 14:33:13 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**fill_tab(char **env, char **new_env, char **arg, int j)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(arg[j]);
	while (env[i] != 0 && (ft_strncmp(arg[j], env[i], n) != 0))
	{
		i++;
		if (env[i] == 0)
			return (env);
	}
	n = 0;
	while (n < i)
	{
		new_env[n] = env[n];
		n++;
	}
	i++;
	while (env[i++] != 0)
	{
		new_env[n] = env[i];
		n++;
	}
	new_env[n] = NULL;
	return (new_env);
}

int			ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

char		**unset_env(char **env, char **arg)
{
	int		i;
	int		j;
	char	**new_env;

	i = ft_tablen(env);
	j = 1;
	if (!(new_env = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	while (arg[j] != 0)
	{
		new_env = fill_tab(env, new_env, arg, j);
		env = new_env;
		j++;
	}
	return (new_env);
}
