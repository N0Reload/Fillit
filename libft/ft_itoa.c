/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:36:32 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/06 12:37:09 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_lenght(int n, int *lenght)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		(*lenght)++;
		nb = -nb;
	}
	if (nb < 10)
	{
		(*lenght)++;
	}
	else
	{
		ft_itoa_lenght(nb / 10, lenght);
		ft_itoa_lenght(nb % 10, lenght);
	}
}

static void		ft_itoa_write(int n, char *str, int index)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb < 10)
	{
		str[index] = nb + '0';
	}
	else
	{
		ft_itoa_write(nb / 10, str, index - 1);
		ft_itoa_write(nb % 10, str, index);
	}
}

char			*ft_itoa(int n)
{
	int		lenght;
	char	*str;

	lenght = 0;
	ft_itoa_lenght(n, &lenght);
	str = ft_strnew(lenght);
	if (str)
		ft_itoa_write(n, str, lenght - 1);
	return (str);
}
