/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 16:02:35 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 14:52:29 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "stdio.h"

char	ft_isnbrs(char *str)
{
	int		i;

	i = 0;
	if (ft_isnbr(str) == 2)
		i++;
	else if (!ft_isnbr(str))
		return (0);
	while (str[i])
	{
		if (!ft_isnbr(&(str[i])))
			return (0);
		i++;
	}
	return (1);
}

char	check_order(t_lem *lem, char *line)
{
	char	ret;

	ret = ON;
	if (line[1] == '#')
	{
		if (!ft_strcmp(&(line[2]), "start"))
		{
			OFLAG = 2;
			lem->in_n_out++;
		}
		else if (!ft_strcmp(&(line[2]), "end"))
		{
			OFLAG = 1;
			lem->in_n_out++;
		}
	}
	return (ret);
}

int		*str_to_tab(char *str, char c)
{
	int		i;
	int		e;
	int		*tab;

	i = -1;
	e = 0;
	while (str[++i])
		if (str[i] == c)
			e++;
	tab = (int *)malloc(sizeof(int) * (e + 1));
	i = 0;
	e = 0;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == c)
		{
			tab[e] = ft_atoi(&(str[i]));
			e++;
		}
		i++;
	}
	tab[e] = -1;
	return (tab);
}

char	get_map_info(t_lem *lem, char *line, char *stat)
{
	if (line[0] == 'L')
		return (ERROR);
	if (line[0] == '#')
		if (line[1] != '#' || *stat)
			return (check_order(lem, line));
	if (!(*stat))
		return (check_for_lems(lem, line, stat));
	else if (*stat == 1)
		return (check_for_room(lem, line, stat));
	else
		return (check_for_link(lem, line, stat));
	return (ON);
}

char	map_anthill(t_lem *lem)
{
	char	ret;
	char	stat;
	char	m_ret;
	char	*line;

	stat = 0;
	line = NULL;
	lem->order_flag = OFF;
	while ((ret = get_next_line(STDIN, &line)) != ERROR)
	{
		m_ret = get_map_info(lem, line, &stat);
		if (m_ret > OFF)
			lem->anthill = ft_strmcat(lem->anthill, ft_strmcat(line, "\n"));
		else
			free(line);
		if (ret == OFF || m_ret <= OFF)
			return (m_ret);
	}
	exit(ERROR);
}
