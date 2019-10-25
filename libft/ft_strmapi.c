/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:03:12 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 15:29:55 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	while ((s + i) && s[i])
		i++;
	dest = ft_strnew(i);
	i = 0;
	if (!dest)
		return (NULL);
	while ((s + i) && s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}
