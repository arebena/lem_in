/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 15:57:29 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 14:43:42 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] != ' ')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	ft_memcpy(name, line, i);
	return (name);
}

char	isroom(char *line)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (line[++i])
	{
		if (flag)
			if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
				return (OFF);
		if (i > 0)
			if (line[i - 1] != ' ' && line[i] == ' ')
				if ((line[i + 1] >= '0' && line[i + 1] <= '9'))
					flag++;
	}
	return ((flag == 2) ? ON : OFF);
}

int		room_by_name(t_lem *lem, char *name)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = ROOMS;
	while (tmp[++i])
		if (!(ft_strcmp(name, tmp[i])))
			return (i);
	return (-1);
}
