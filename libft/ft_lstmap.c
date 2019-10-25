/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:40 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 23:40:18 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_free(void *element, size_t n)
{
	n = n + 1;
	if (element)
		free(element);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *new;
	t_list *temp;

	map = NULL;
	while (lst)
	{
		temp = f(lst);
		new = ft_lstnew(temp->content, temp->content_size);
		if (!new)
		{
			ft_lstdel(&map, &ft_free);
			return (NULL);
		}
		ft_lstadd(&map, new);
		lst = lst->next;
	}
	ft_lstrev(&map);
	return (map);
}
