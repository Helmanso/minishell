/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:31:38 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/14 15:21:15 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		ft_putstr(KRED"$" KGRN ">" KYEL "ファックユー");
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr("\nSignal d'interruption\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGKILL)
	{
		ft_putstr("\nUser kill the process: Stopping.\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGTERM)
	{
		ft_putstr("\n Termination dial signal\n");
		exit(EXIT_FAILURE);
	}
}

void	block_sig(void)
{
	int i;

	i = 0;
	while (i < 33)
		signal(i++, sighandler);
}
