/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:58:52 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 21:58:53 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	t_board	board;

	if (argc != 2)
		return (usage(argv[0]));
	board = parse_file(argv[1]);
	board = solve_board(board);
	display_result(board);
	return (0);
}
