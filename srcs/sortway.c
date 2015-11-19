/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 17:27:12 by arebena           #+#    #+#             */
/*   Updated: 2015/06/28 20:31:08 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#include <stdio.h>

t_way	*wayrewind(t_way *lst, t_way *nod)
{
    t_way	*tmp;

    tmp = lst;
    if (nod == lst)
		return (NULL);
    while (tmp->next != nod)
        tmp = tmp->next;
    return (tmp);
}

t_way	*wayswap(t_way *way, t_way *way1, t_way *way2)
{
	t_way	*tmp;

	tmp = wayrewind(way, way1);
	if (tmp)
		tmp->next = way2;
	way1->next = way2->next;
	way2->next = way1;
	return (way2);
}

void	id_order(t_way *way)
{
	int		id;
	t_way	*tmp;

	id = 0;
	tmp = way;
	while (tmp)
	{
		tmp->id = id;
		id++;
		tmp = tmp->next;
	}
}

t_way	*ft_sortway(t_way *way)
{
	int		flag;
	t_way	*tmp;
	t_way	*bis;

	tmp = way;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while (tmp)
		{
			if (bis = tmp->next, tmp->next)
				if (tmp->size > bis->size)
				{
					flag = 1;
					tmp = wayswap(way, tmp, tmp->next);
					printf("swap (  %d  <->  %d  )\n", tmp->id, bis->id);
					if (way == tmp->next)
						way = tmp;
				}
			tmp = tmp->next;
		}
		tmp = way;
	}
	id_order(way);
	return (way);
}
