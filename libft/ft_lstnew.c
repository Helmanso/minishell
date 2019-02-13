/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:45:41 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 21:40:41 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	int			i;
	void		*cont;
	t_list		*to_return;

	i = 0;
	if (!(cont = malloc(content_size)))
		return (NULL);
	if (content)
		ft_memcpy(cont, content, content_size);
	if (!(to_return = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	to_return->content = cont;
	if (!content)
	{
		to_return->content_size = 0;
		to_return->content = NULL;
	}
	else
	{
		to_return->content_size = content_size;
		to_return->content = cont;
	}
	to_return->next = NULL;
	return (to_return);
}
