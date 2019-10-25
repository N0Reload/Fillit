/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:09 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 21:59:10 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_links(t_piece *piece, char *str, int line)
{
	int	links;
	int	i;

	links = 0;
	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
		{
			if (line > 0 && piece->shape[(line - 1) * 4 + i] == '#')
				++links;
			if (i > 0 && str[i - 1] == '#')
				++links;
		}
		++i;
	}
	return (links);
}

static void	check_errors(int links, t_piece *piece)
{
	if (links < 3)
		error();
	if (ft_strccount(piece->shape, '#') != 4)
		error();
	if (ft_strccount(piece->shape, '.') != 12)
		error();
}

static char	*get_line(int fd)
{
	char	*result;

	result = ft_strnew(4);
	if (read(fd, result, 5) != 5)
		error();
	if (result[4] != '\n')
		error();
	result[4] = 0;
	return (result);
}

t_piece		*get_piece(int fd, int letter)
{
	int		line;
	char	*str;
	int		links;
	t_piece	*piece;

	line = 0;
	links = 0;
	piece = new_piece(letter);
	while (line < 4)
	{
		str = get_line(fd);
		links += check_links(piece, str, line);
		ft_strcat(piece->shape, str);
		free(str);
		line++;
	}
	check_errors(links, piece);
	piece->height = 4;
	trim_piece(piece);
	return (piece);
}
