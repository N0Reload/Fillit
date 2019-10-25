/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:36:43 by tde-oliv          #+#    #+#             */
/*   Updated: 2017/11/14 16:05:57 by tde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_list	*find_fd(t_list *lst, int fd)
{
	t_info *current;

	if (!lst)
	{
		return (NULL);
	}
	while (lst)
	{
		current = (t_info*)lst->content;
		if (current->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static t_info	*get_informations(t_list **lst_info, int fd)
{
	t_list *element;
	t_info *info;

	element = find_fd(*lst_info, fd);
	if (element)
		return ((t_info*)element->content);
	info = (t_info*)malloc(sizeof(t_info));
	if (info)
	{
		info->fd = fd;
		info->temp_lenght = 0;
		info->temp = ft_strnew(0);
		element = ft_lstnew(NULL, 0);
		if (element)
		{
			element->content = info;
			element->content_size = sizeof(t_info*);
			ft_lstadd(lst_info, element);
			info = element->content;
			return (info);
		}
		free(info);
	}
	return (NULL);
}

static int		check_temp(t_info *fd_info, char **line)
{
	char	*str;
	int		index;

	str = ft_strchr(fd_info->temp, '\n');
	if (str)
	{
		index = str - fd_info->temp;
		*line = ft_strsub(fd_info->temp, 0, index);
		if (fd_info->temp_lenght > index + 1)
			str = ft_strsub(fd_info->temp, index + 1,
					fd_info->temp_lenght - (index + 1));
		else
			str = ft_strnew(0);
		fd_info->temp_lenght = ft_strlen(str);
		free(fd_info->temp);
		fd_info->temp = str;
		return (1);
	}
	return (0);
}

static int		update_temp(t_info *fd_info, char **line, int readed)
{
	char	*temp;
	int		temp_lenght;

	if (readed == 0)
	{
		*line = ft_strdup(fd_info->temp);
		free(fd_info->temp);
		fd_info->temp = ft_strnew(0);
		temp_lenght = fd_info->temp_lenght;
		fd_info->temp_lenght = 0;
		return (temp_lenght != 0);
	}
	else
	{
		temp_lenght = fd_info->temp_lenght + readed;
		temp = malloc(temp_lenght + 1);
		ft_memcpy(temp, fd_info->temp, fd_info->temp_lenght);
		ft_memcpy(temp + fd_info->temp_lenght, fd_info->buffer, readed);
		temp[temp_lenght] = '\0';
		free(fd_info->temp);
		fd_info->temp = temp;
		fd_info->temp_lenght = temp_lenght;
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files_inforations;
	t_info			*fd_info;
	int				readed;

	if (fd < 0 || !line)
		return (-1);
	fd_info = get_informations(&files_inforations, fd);
	if (!fd_info)
		return (-1);
	while (1)
	{
		if (check_temp(fd_info, line))
			return (1);
		readed = read(fd, &(fd_info->buffer), BUFF_SIZE);
		if (readed == -1)
			return (-1);
		readed = update_temp(fd_info, line, readed);
		if (readed != -1)
			return (readed);
	}
	return (1);
}
