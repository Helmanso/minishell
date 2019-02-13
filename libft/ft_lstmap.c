/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:38:19 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 21:59:03 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*start;
	t_list	*prev;
	int		i;

	i = 0;
	while (lst != NULL)
	{
		current = f(lst);
		if (current == NULL)
			return (NULL);
		if (i >= 1)
		{
			prev->next = current;
			if (i == 1)
				start = prev;
		}
		lst = lst->next;
		prev = current;
		i++;
	}
	current->next = NULL;
	return (start);
}
