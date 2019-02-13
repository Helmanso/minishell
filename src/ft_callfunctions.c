/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:28:35 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/22 15:09:26 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**call_functions1(char *envp[], char **line, t_args *arg)
{
	static char	**envlist;
	static char	a;

	arg = builincmds(line);
	if (!envlist)
	{
		envlist = get_env(envp, "env");
		envlist[15] = ft_strdup("TERM=xterm");
	}
	if (arg->env == 1)
		ft_printenv(envlist);
	if (arg->cd == 1)
		envlist = ft_cd(envp, line, envlist);
	if (arg->setenv == 1 && line[2])
	{
		if (!ft_strcmp(line[1], "PATH"))
			a = 5;
		envlist = ft_setenv(envlist, line[1], line[2], 1);
	}
	if (arg->unsetenv == 1)
		envlist = unset_env(envlist, line);
	if (arg->echo == 1)
		echo_builtin(line, envlist);
	return (envlist);
}

void	call_functions(char *envp[], char **line, t_args *arg)
{
	char		**parse;
	char		**splited;
	static char	**envlist;
	static char	a;

	envlist = call_functions1(envp, line, arg);
	if (ft_strcmp(line[0], "cd"))
	{
		if (a == 5 && ft_strcmp(line[1], "/bin"))
		{
			ft_putchar('\n');
			a = 0;
		}
		else if (builincmds1(line) == 0)
		{
			splited = ft_strsplit(envlist[findpathenv(envlist)], ':');
			splited[0] = ft_strchr(splited[0], '/');
			parse = lahyamethod(line, splited);
			if (parse != NULL)
				ft_forkini(parse, envlist);
		}
	}
}

void	loop(char *envp[])
{
	char	**line;
	t_args	*arg;
	char	*line2;
	int		deamond;
	int		i;

	i = 0;
	block_sig();
	arg = NULL;
	while (1)
	{
		ft_putstr(KRED"$" KGRN ">" KYEL "ファックユー");
		deamond = get_next_line(0, &line2);
		line = lsh_split_line(line2);
		if (!line[i])
			loop(envp);
		else if (!ft_strcmp(line[0], "exit"))
			kill(0, SIGKILL);
		else
			call_functions(envp, line, arg);
	}
}

int		main(int argc, char **argv, char *envp[])
{
	argc = 0;
	argv = 0;
	loop(envp);
}
