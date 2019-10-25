/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:20 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:06:13 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		piece_to_coord(t_piece *piece, int index)
{
	t_point	point;

	point.y = index / piece->width;
	point.x = index % piece->width;
	return (point);
}

int			piece_to_index(t_piece *piece, t_point coord)
{
	return (coord.y * piece->width + coord.x);
}

int			piece_fits(t_board board, t_piece *piece, t_point anchor)
{
	int		i;
	int		j;

	if (piece->width > board.size || piece->height > board.size)
		return (0);
	i = 0;
	while (i < piece->width * piece->height)
	{
		j = board_to_index(board, add_points(piece_to_coord(piece, i), anchor));
		if (piece->shape[i] == '#' && board.blocks[j] != '.')
			return (0);
		++i;
	}
	return (1);
}

int			solve_piece(t_board board, t_piece *piece)
{
	t_point	anchor;

	if (piece == NULL)
		return (1);
	anchor = point(0, 0);
	while (anchor.y <= board.size - piece->height)
	{
		anchor.x = 0;
		while (anchor.x <= board.size - piece->width)
		{
			if (piece_fits(board, piece, anchor))
			{
				place_piece(board, piece, anchor);
				if (solve_piece(board, piece->next))
					return (1);
				remove_piece(board, piece, anchor);
			}
			++(anchor.x);
		}
		++(anchor.y);
	}
	return (0);
}
