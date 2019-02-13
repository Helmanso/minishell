/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:26:54 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/13 20:38:39 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_args(size_t n, va_list *ap, char *bufarg[])
{
	size_t	i;
	size_t	total;
	char	*tmp;

	i = 0;
	total = 0;
	while (i < n && i < MAXARG)
	{
		tmp = va_arg(*ap, char *);
		total += ft_strlen(tmp);
		bufarg[i] = tmp;
		i += 1;
	}
	return (total);
}

char			*ft_strnjoin(size_t n, ...)
{
	size_t	total;
	size_t	i;
	va_list	ap;
	char	*res;
	char	*bufarg[MAXARG];

	va_start(ap, n);
	total = get_args(n, &ap, bufarg);
	va_end(ap);
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	*res = '\0';
	i = 0;
	while (i < n && i < MAXARG)
	{
		ft_strcat(res, bufarg[i]);
		i += 1;
	}
	return (res);
}

char			**findenv(char **environ, const char *envname)
{
	while (*environ)
	{
		if (ft_strnequ(*environ, envname, ft_strlen(envname)))
			return (environ);
		environ++;
	}
	return (NULL);
}

static char		**new_slot(char **environ,
		const char *envname, const char *enval)
{
	char		**newenv;
	size_t		i;

	i = 0;
	while (environ[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	newenv[i + 1] = NULL;
	ft_memcpy(newenv, environ, sizeof(char *) * i);
	if (!(newenv[i] = ft_strnjoin(3, envname, "=", enval)))
	{
		deltab(newenv);
		return (NULL);
	}
	free(environ);
	return (newenv);
}

char			**ft_setenv(char **environ, char *envname,
		char *enval, int overwrite)
{
	char		**slot;
	int			envsize[2];

	if (!environ)
		return (environ);
	if (ft_strchr(envname, '='))
		return (environ);
	envsize[0] = ft_strlen(envname);
	envsize[1] = ft_strlen(enval);
	if (!(slot = findenv(environ, envname)))
		return (new_slot(environ, envname, enval));
	if (!overwrite)
		return (environ);
	if (ft_strlen(*slot) >= envsize[0] + envsize[1] + 1)
	{
		ft_strcpy(*slot + envsize[0] + 1, enval);
		return (environ);
	}
	free(*slot);
	*slot = ft_strnjoin(3, envname, "=", enval);
	return (environ);
}
