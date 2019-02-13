/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:29:45 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/22 14:34:13 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cdbugs(char **line)
{
	struct stat	ststat;

	lstat(line[1], &ststat);
	if (line[1] && line[2])
	{
		ft_putstr(line[0]);
		ft_putstr(": string not in pwd: ");
		ft_putstr(line[1]);
	}
	if (S_ISREG(ststat.st_mode))
	{
		ft_putstr(line[0]);
		ft_putstr(": not a directory: ");
		ft_putstr(line[1]);
	}
}

int		ft_getenv(char **envlist)
{
	int	i;

	i = 0;
	while (envlist[i])
	{
		if (ft_strstr(envlist[i], "OLDPWD"))
			return (i);
		i++;
	}
	return (1);
}

char	*ft_cd1(char **line, char **envlist1)
{
	char		buf[BUFF_SIZE];
	static char *oldpath;

	oldpath = ft_strdup(getcwd(buf, sizeof(buf)));
	if ((!ft_strcmp(line[0], "cd") &&
				!line[1]) || (ft_strlen(line[1]) == 1))
		chdir(ft_strchr(envlist1[0], '/'));
	else
		chdir(ft_strjoin(ft_strchr(envlist1[0], '/'),
					ft_strchr(line[1], '/')));
	return (oldpath);
}

char	**ft_cd(char *envp[], char **line, char **envlist)
{
	char		**envlist1;
	static char	*oldpath;
	char		buf[BUFF_SIZE];

	ft_setenv(envlist, "OLDPWD", ft_strjoin(getcwd(buf, sizeof(buf)), "\n"), 1);
	envlist1 = get_env(envp, "HOME");
	ft_cdbugs(line);
	if ((!ft_strcmp(line[0], "cd") && !line[1]) ||
			(!ft_strcmp(line[0], "cd") && ft_strstr(line[1], "~")))
		oldpath = ft_cd1(line, envlist1);
	else if (!ft_strcmp(line[0], "cd") && !ft_strcmp(line[1], "-"))
		chdir(oldpath);
	else if (!(access(line[1], F_OK)))
	{
		oldpath = ft_strdup(getcwd(buf, sizeof(buf)));
		chdir(line[1]);
	}
	else if ((chdir(line[1]) && access(line[1], F_OK)))
	{
		ft_putstr(line[0]);
		ft_putstr(": no such file or directory : ");
		ft_putendl(line[1]);
	}
	ft_setenv(envlist, "PWD", ft_strjoin(getcwd(buf, 100), "\n"), 1);
	return (envlist);
}
