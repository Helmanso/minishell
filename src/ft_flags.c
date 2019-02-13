/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:25:56 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/22 15:11:12 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*builincmds(char **line)
{
	t_args *arg;

	arg = (t_args*)malloc(sizeof(t_args));
	arg->env = 0;
	if (!ft_strcmp(line[0], "echo"))
		arg->echo = 1;
	else if (!ft_strcmp(line[0], "cd"))
		arg->cd = 1;
	else if (!ft_strcmp(line[0], "setenv"))
		arg->setenv = 1;
	else if (!ft_strcmp(line[0], "unsetenv"))
		arg->unsetenv = 1;
	else if (!ft_strcmp(line[0], "exit"))
		arg->exit = 1;
	else if (!ft_strcmp(line[0], "env"))
		arg->env = 1;
	return (arg);
}

int		builincmds1(char **line)
{
	t_args *arg;

	arg = (t_args*)malloc(sizeof(t_args));
	arg->env = 0;
	if (!ft_strcmp(line[0], "echo"))
		return (1);
	else if (!ft_strcmp(line[0], "cd"))
		return (1);
	else if (!ft_strcmp(line[0], "setenv"))
		return (1);
	else if (!ft_strcmp(line[0], "unsetenv"))
		return (1);
	else if (!ft_strcmp(line[0], "exit"))
		return (1);
	else if (!ft_strcmp(line[0], "env"))
		return (1);
	return (0);
}

char	*notfoundcmd(char **line)
{
	ft_putstr(line[0]);
	ft_putstr(": command not found \n");
	return (NULL);
}

void	ft_printenv(char **envlist)
{
	int	i;

	i = 0;
	while (envlist[i])
		ft_putstr(envlist[i++]);
	ft_putchar('\n');
}
