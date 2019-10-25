/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:59:33 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/19 22:01:46 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void		right(t_point *point)
{
	point->x = point->x + 1;
}

void		wrap(t_point *point)
{
	point->x = 0;
	point->y = point->y + 1;
}

t_point		add_points(t_point a, t_point b)
{
	return (point(a.x + b.x, a.y + b.y));
}
