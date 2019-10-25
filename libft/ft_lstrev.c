/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:42:49 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 12:42:50 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list *last;
	t_list *current;
	t_list *next;

	last = NULL;
	while (*begin_list)
	{
		current = *begin_list;
		next = current->next;
		current->next = last;
		last = current;
		*begin_list = next;
	}
	*begin_list = current;
}
