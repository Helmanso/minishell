/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:31:02 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/14 15:23:24 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_forkini(char **args, char **envlist)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(args[0], args, envlist);
	else
		waitpid(pid, NULL, 0);
	return (pid);
}
