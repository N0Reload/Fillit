/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:58:55 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 16:01:10 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_words(char const *s, char c)
{
	int switcher;

	switcher = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		switcher = 1;
		s++;
	}
	if (*s)
		return (switcher + count_words(s, c));
	return (switcher);
}

static int		next_word_size(char const *s, char c, int *size)
{
	int jump;

	jump = 0;
	*size = 0;
	while (*s && *s == c)
	{
		s++;
		jump++;
	}
	while (*s && *s != c)
	{
		(*size)++;
		s++;
	}
	return (jump);
}

static char		**ft_fake(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*));
	tab[0] = NULL;
	return (tab);
}

static char		**ft_strsplit_checked(char const *s, char c)
{
	char	**tab;
	char	jump;
	int		index;
	int		words;
	int		word_size;

	words = count_words(s, c);
	tab = (char**)malloc(sizeof(char*) * (words + 1));
	if (tab)
	{
		index = 0;
		while (index < words)
		{
			jump = next_word_size(s, c, &word_size);
			s += jump;
			tab[index] = ft_strnew(word_size);
			if (tab[index])
				ft_strncpy(tab[index], s, word_size);
			s += word_size;
			index++;
		}
		tab[words] = NULL;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (ft_fake());
	return (ft_strsplit_checked(s, c));
}
