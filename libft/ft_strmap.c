/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:03:27 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 15:31:04 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		dest[i] = f(s[i]);
		i++;
	}
	return (dest);
}
