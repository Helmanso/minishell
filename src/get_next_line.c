/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:34:42 by helmanso          #+#    #+#             */
/*   Updated: 2019/02/13 15:19:44 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line.h"

static	int			checkerror(int fd, char **line, char **str)
{
	char buff[BUFF_SIZE1];

	if (fd == -1 || line == NULL || (read(fd, buff, 0) < 0))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE1);
	return (0);
}

static	char		*readlines(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (str);
	}
	else if (ft_strlen(str))
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (str);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	static	char	*str[100];
	char			*str1;
	char			buff[BUFF_SIZE1 + 1];
	int				ret;

	if ((checkerror(fd, line, str) == -1))
		return (-1);
	while (!(ft_strchr(str[fd], '\n')) &&
			(ret = read(fd, buff, BUFF_SIZE1)) > 0)
	{
		buff[ret] = '\0';
		str1 = str[fd];
		str[fd] = ft_strrjoin(str1, buff, ret);
		free(str1);
	}
	*line = ft_strsub(str[fd], 0, ft_strnlen(str[fd]));
	if (readlines(str[fd]) == NULL)
		return (0);
	return (1);
}
