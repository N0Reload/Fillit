/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:42:27 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 23:49:45 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *element;

	element = (t_list*)malloc(sizeof(t_list));
	if (element)
	{
		if (content)
		{
			element->content = (void*)malloc(content_size);
			if (!element->content)
			{
				free(element);
				return (NULL);
			}
			ft_memcpy(element->content, content, content_size);
			element->content_size = content_size;
			element->next = NULL;
		}
		else
		{
			element->content = NULL;
			element->content_size = 0;
			element->next = NULL;
		}
	}
	return (element);
}
