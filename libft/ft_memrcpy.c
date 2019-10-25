/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:05:28 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/16 01:09:43 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = dest;
	s2 = src;
	while (n--)
		s1[n] = s2[n];
	return (dest);
}
