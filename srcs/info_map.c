/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 16:09:11 by arebena           #+#    #+#             */
/*   Updated: 2016/09/19 17:22:09 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

void	insert_row(char ***room, char *content, int spot)
{
	int			i;
	char		**tmp;
	static int	id = 2;

	i = -1;
	if (spot >= 0)
	{
		free((*room)[spot]);
		(*room)[spot] = ft_strdup(content);
	}
	else
	{
		tmp = (char **)malloc(sizeof(char *) * (id + 2));
		while ((*room)[++i])
			tmp[i] = (*room)[i];
		tmp[id] = ft_strdup(content);
		tmp[id + 1] = NULL;
		id++;
		free(*room);
		*room = tmp;
	}
}

char	check_for_room(t_lem *lem, char *line, char *stat)
{
	char		*name;

	if (!isroom(line))
		return (check_for_link(lem, line, stat));
	name = get_name(line);
	insert_row(&ROOMS, name, OFLAG - 1);
	if (OFLAG)
		OFLAG = 0;
	free(name);
	(void)stat;
	return (ON);
}

char	**matrix_init(t_lem *lem)
{
	int		i;
	int		e;
	char	**tmp;
	char	**n_matrix;

	i = 0;
	tmp = lem->rooms;
	while (tmp[i])
		i++;
	n_matrix = (char **)malloc(sizeof(char *) * (i + 1));
	n_matrix[i] = NULL;
	e = -1;
	while (++e != i)
	{
		n_matrix[e] = (char *)malloc(sizeof(char) * (i + 1));
		ft_bzero(n_matrix[e], i);
		n_matrix[e][i] = -1;
	}
	lem->mlen = e;
	lem->m_esc = ft_strmcat(ft_strmcat(ft_strdup("\033["), ft_itoa(e + 1)), "A");
	return (n_matrix);
}

void	matrix_update(t_lem *lem, int one, int two)
{
	lem->matrix[one][two] = 1;
	lem->matrix[two][one] = 1;
}

char	check_for_link(t_lem *lem, char *line, char *stat)
{
	int		i;
	int		one;
	int		two;
	char	*tmp;

	i = 0;
	if (!islink(line))
		return (OFF);
	if (*stat == 1)
		lem->matrix = matrix_init(lem);
	*stat = 2;
	tmp = ft_strdup(line);
	while (tmp[i] != '-')
		i++;
	tmp[i] = 0;
	one = room_by_name(lem, tmp);
	two = room_by_name(lem, &(tmp[i + 1]));
	if (one < 0 || two < 0 || one == two)
		return (OFF);
	matrix_update(lem ,one, two);
	free(tmp);
	return (ON);
}

char	check_for_lems(t_lem *lem, char *line, char *stat)
{
	int		lems;

	lems = 0;
	if (ft_isnbrs(line))
		if ((lems = (ft_atoi(line))) > 0)
		{
			*stat += 1;
			lem->lems = lems;
		}
	return ((lems > 0) ? ON : ERROR);
}
