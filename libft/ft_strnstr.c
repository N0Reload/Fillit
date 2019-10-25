/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:12:39 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/16 01:12:40 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len2;

	len2 = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while ((*s1) && (n-- >= len2))
	{
		if ((*s1 == *s2) && (ft_memcmp(s1, s2, len2) == 0))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
