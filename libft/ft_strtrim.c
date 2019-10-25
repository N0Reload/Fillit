/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:08:02 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 15:35:29 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;

	if (!s)
		return (NULL);
	while (s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	i = 0;
	j = 0;
	while ((s + i) && s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			j++;
		else
			j = 0;
		i++;
	}
	i -= j;
	dest = ft_strnew(i);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, i);
	return (dest);
}
