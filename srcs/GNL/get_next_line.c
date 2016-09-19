/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:28:20 by arebena           #+#    #+#             */
/*   Updated: 2015/02/24 16:30:19 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	archiving(char **line, char *page, int fd, int del)
{
	static t_list	*archiv = NULL;
	t_list			*t_tmp;
	char			*tmp;
	char			x;

	if (x = ON, !archiv && page && !del)
		archiv = LXN(page, fd);
	if (t_tmp = archiv, archiv)
		while (t_tmp && (int)(t_tmp->content_size) != fd)
			t_tmp = t_tmp->next;
	if (!line && t_tmp && !del)
		t_tmp->content = page;
	else if (page && !t_tmp && !del)
		ft_lstaddend(&archiv, LXN(page, fd));
	else if (line && t_tmp && !del)
	{
		tmp = (char *)t_tmp->content;
		x = line_sorter(line, tmp, fd);
		free(tmp);
	}
	else if (del && t_tmp)
		if (!(t_tmp->content = NULL))
			archiv = ft_noddel(&archiv, &t_tmp);
	return ((!page) ? x : 0);
}

char	line_sorter(char **line, char *buf, int fd)
{
	int		ll;
	int		lb;
	char	*n_line;

	lb = ft_strclen(buf, '\n');
	ll = (*line) ? ft_strlen(*line) : 0;
	n_line = ft_strnew(lb + ll + 1);
	if (*line)
		n_line = ft_strcat(n_line, *line);
	n_line = ft_strncat(n_line, buf, lb);
	if (*line)
		free(*line);
	*line = n_line;
	if (buf[lb] == '\n')
		return (archiving(NULL, SDUP((buf[++lb]) ? &(buf[lb]) : ""), fd, OFF));
	return (ON);
}

int		get_next_line(int const fd, char **line)
{
	char	*buf;
	char	eol;
	int		ret;

	ret = ON;
	eol = ON;
	if (BUFF_SIZE <= 0 || line == NULL					\
	|| BUFF_SIZE > MAX_BUFF_SIZE						\
	|| !(buf = ft_strnew(BUFF_SIZE + 1)))
		return (FAIL);
	*line = NULL;
	if ((archiving(line, NULL, fd, OFF)))
		while (eol && ret > 0)
		{
			if ((ret = read(fd, buf, BUFF_SIZE)) == FAIL)
				break ;
			buf[ret] = 0;
			eol = (buf[0]) ? line_sorter(line, buf, fd) : 0;
		}
	if (!ret)
		archiving(NULL, NULL, fd, ON);
	free(buf);
	return ((ret > 0) ? ON : ret);
}
