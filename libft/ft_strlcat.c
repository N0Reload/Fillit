/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:44 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/16 01:20:51 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_base_size;
	size_t	src_size;
	size_t	i;

	dest_base_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size < dest_base_size + 1)
		return (src_size + size);
	i = 0;
	while ((dest_base_size + i) < (size - 1) && i < src_size)
	{
		dest[dest_base_size + i] = src[i];
		i++;
	}
	dest[dest_base_size + i] = '\0';
	return (dest_base_size + src_size);
}
