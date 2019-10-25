/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:58:44 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:03:37 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_point
{
	int			x;
	int			y;
}						t_point;

typedef struct			s_piece
{
	int					width;
	int					height;
	char				*shape;
	char				letter;
	struct s_piece		*next;
}						t_piece;

typedef struct			s_board
{
	int					size;
	char				*blocks;
	t_piece				*pieces;
}						t_board;

t_board					new_board(t_piece *pieces);
void					place_piece(t_board board, t_piece *piece,
		t_point point);
void					remove_piece(t_board board, t_piece *piece,
		t_point point);
int						piece_fits(t_board board, t_piece *piece,
		t_point point);
int						board_to_index(t_board board, t_point coord);
t_board					solve_board(t_board board);
int						solve_piece(t_board board, t_piece *piece);
void					display_result(t_board board);

t_piece					*get_piece(int fd, int letter);
int						skip_line(int fd);
t_board					parse_file(char *filename);

t_piece					*new_piece(char letter);
void					trim_piece(t_piece *piece);
int						pieces_qty(t_piece *piece);
void					add_piece(t_piece *list, t_piece *new);
t_point					piece_to_coord(t_piece *piece, int index);
int						piece_to_index(t_piece *piece, t_point point);

t_point					add_points(t_point a, t_point b);
t_point					point(int x, int y);
void					right(t_point *point);
void					wrap(t_point *point);

int						ft_strccount(char *str, char c);
void					error(void);
int						usage(char *name);

#endif
