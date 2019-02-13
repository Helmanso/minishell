/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:43:37 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/22 14:03:51 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**biriway(char *filename, char **line)
{
	if (!access(filename, F_OK))
	{
		line[0] = ft_strdup(filename);
		return (line);
	}
	return (NULL);
}

char	**lahyamethod(char **line, char **splited)
{
	int		i;
	char	*filename;

	i = 0;
	while (splited[i])
	{
		filename = ft_strjoin(splited[i], ft_strjoin("/", line[0]));
		if (biriway(filename, line) == NULL)
			i++;
		else
			return (biriway(filename, line));
	}
	if (!ft_strstr(line[0], "/bin") && (builincmds1(line) == 0))
	{
		notfoundcmd(line);
		return (NULL);
	}
	return (line);
}

int		findpathenv(char **envlist)
{
	int	i;

	i = 0;
	while (envlist[i])
	{
		if (ft_strstr(envlist[i], "PATH"))
			return (i);
		i++;
	}
	return (1);
}

char	**get_env(char **envp, char *envvar)
{
	char	**str;
	int		i;

	i = 0;
	str = (char**)malloc(sizeof(char) * BUFF_SIZE);
	while (*envp)
	{
		str[i] = ft_strnew(ft_strlen(*envp));
		if (ft_strstr(*envp, envvar) && ft_strcmp(envvar, "env"))
		{
			str[i] = ft_strdup(*envp);
			return (str);
		}
		else if (!ft_strcmp(envvar, "env"))
		{
			str[i] = ft_strdup(*envp);
			str[i] = ft_strjoin(str[i], "\n");
			i++;
		}
		envp++;
	}
	return (str);
}
