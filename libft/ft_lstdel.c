/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:16 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 21:41:26 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*temp;

	current = *alst;
	while (current != NULL)
	{
		temp = current->next;
		del(current->content, current->content_size);
		free(current);
		current = temp;
	}
	*alst = NULL;
}
