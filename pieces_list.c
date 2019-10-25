/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:04 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:00:06 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_piece(t_piece *list, t_piece *new)
{
	while (list->next)
		list = list->next;
	list->next = new;
}

t_piece	*new_piece(char letter)
{
	t_piece	*piece;

	piece = ft_memalloc(sizeof(t_piece));
	if (!piece)
		error();
	piece->width = 4;
	piece->shape = ft_strnew(16);
	piece->letter = letter;
	return (piece);
}

void	remove_piece(t_board board, t_piece *piece, t_point anchor)
{
	int	i;
	int	j;

	i = 0;
	while (i < piece->width * piece->height)
	{
		j = board_to_index(board, add_points(piece_to_coord(piece, i), anchor));
		if (piece->shape[i] == '#')
			board.blocks[j] = '.';
		++i;
	}
}

int		pieces_qty(t_piece *list)
{
	int	total;

	total = 0;
	while (list)
	{
		list = list->next;
		++total;
	}
	return (total);
}
