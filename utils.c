/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:26 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:00:17 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" source_file");
	return (0);
}

void	display_result(t_board board)
{
	int i;

	i = 0;
	while (i < board.size)
	{
		write(1, board.blocks + board.size * i, board.size);
		write(1, "\n", 1);
		++i;
	}
}

int		skip_line(int fd)
{
	char	c;
	int		res;

	res = read(fd, &c, 1);
	if (res == -1)
		error();
	if (res == 0)
		return (0);
	if (c == '\n')
		return (1);
	error();
	return (0);
}

void	error(void)
{
	ft_putendl("error");
	exit(0);
}

int		ft_strccount(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
