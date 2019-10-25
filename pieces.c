/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:00 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:00:37 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place_piece(t_board board, t_piece *piece, t_point anchor)
{
	int	i;
	int	j;

	i = 0;
	while (i < piece->width * piece->height)
	{
		j = board_to_index(board, add_points(piece_to_coord(piece, i), anchor));
		if (piece->shape[i] == '#')
			board.blocks[j] = piece->letter;
		++i;
	}
}

static int	can_remove_col(t_piece *piece, int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (piece->shape[4 * i + col] == '#')
			return (0);
		++i;
	}
	return (1);
}

static void	swap_shapes(t_piece *piece, t_point anchor)
{
	int		i;
	int		j;
	char	*str;
	t_point	pt;

	str = ft_strnew(piece->width * piece->height);
	i = 0;
	while (i < piece->width * piece->height)
	{
		pt = point(i % piece->width, i / piece->width);
		pt = add_points(pt, anchor);
		j = pt.x + 4 * pt.y;
		str[i] = piece->shape[j];
		++i;
	}
	free(piece->shape);
	piece->shape = str;
}

void		trim_piece(t_piece *piece)
{
	t_point	anchor;
	char	*b;

	b = "....";
	anchor = point(0, 0);
	while (!ft_strncmp(b, piece->shape + 4 * anchor.y, 4))
	{
		++(anchor.y);
		--(piece->height);
	}
	while (!ft_strncmp(b, piece->shape + 4 * (anchor.y + piece->height - 1), 4))
		--(piece->height);
	while (can_remove_col(piece, anchor.x))
	{
		++(anchor.x);
		--(piece->width);
	}
	while (can_remove_col(piece, anchor.x + piece->width - 1))
		--(piece->width);
	swap_shapes(piece, anchor);
}
