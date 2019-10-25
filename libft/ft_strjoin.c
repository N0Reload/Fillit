/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:26 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 15:28:51 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1lenght;
	int		s2lenght;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1lenght = ft_strlen(s1);
	s2lenght = ft_strlen(s2);
	dest = ft_strnew(s1lenght + s2lenght);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, s1lenght);
	ft_memcpy(dest + s1lenght, s2, s2lenght);
	return (dest);
}
