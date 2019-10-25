/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:58:34 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 21:58:35 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	parse_file(char *filename)
{
	int		fd;
	t_piece	*list;
	t_board	board;
	char	letter;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error();
	letter = 'A';
	list = get_piece(fd, letter);
	while (skip_line(fd))
		add_piece(list, get_piece(fd, ++letter));
	if (pieces_qty(list) > 26)
		error();
	close(fd);
	board = new_board(list);
	return (board);
}
