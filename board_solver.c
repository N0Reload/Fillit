/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:58:39 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:43:45 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		new_board(t_piece *pieces)
{
	t_board		board;
	int			size;
	int			qty;

	qty = pieces_qty(pieces) * 4;
	size = 1;
	while (size * size < qty)
		++size;
	board.size = size;
	board.blocks = ft_strnew(board.size * board.size);
	if (!board.blocks)
		error();
	ft_memset(board.blocks, '.', board.size * board.size);
	board.pieces = pieces;
	return (board);
}

int			board_to_index(t_board board, t_point coord)
{
	return (coord.y * board.size + coord.x);
}

t_board		solve_board(t_board board)
{
	while (!solve_piece(board, board.pieces))
	{
		++(board.size);
		free(board.blocks);
		board.blocks = ft_strnew(board.size * board.size);
		if (!board.blocks)
			error();
		ft_memset(board.blocks, '.', board.size * board.size);
	}
	return (board);
}
