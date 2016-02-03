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

#include "lem_in.h"

void    way_swap(t_way *a, t_way *b)
{
	int     *tmp;
	int     itmp;

	tmp = a->way;
	itmp = a->len;
	a->way = b->way;
	a->len = b->len;
	b->way = tmp;
	b->len = itmp;
}

void    sort_way(t_way *way)
{
	int     flag;
	t_way   *tmp;

	flag = ON;
	while (flag)
	{
		flag = OFF;
		tmp = way;
		while (tmp)
		{
			if (tmp->next)
				if (tmp->len > tmp->next->len)
				{
					way_swap(tmp, tmp->next);
					flag = ON;
				}
			tmp = tmp->next;
		}
	}
}

void    lem_on_way(t_lem *lem)
{
	t_way   *way;
	int     lem_on;
	int     lems;
	int     id;

	id = 1;
	lems = lem->lems;
	way = lem->shorter;
	while (way)
	{
		lem_on = lem->short_size - (way->len - 1);
		lems -= lem_on;
		if (lems < 0)
			lem_on += lems;
		way->id = id;
		way->lem_on = lem_on;
		id++;
		way = way->next;
	}
}

t_lemin *lem_del(t_lem *lem, int id)
{
	t_lemin *ret;
	t_lemin *tmp;
	t_lemin *tmp_b;

	tmp = lem->lem_in;
	if (tmp->id == id)
		ret = lem->lem_in = lem->lem_in->next;
	else
	{
		while (tmp->next->id != id)
			tmp = tmp->next;
		tmp_b = tmp->next;
		tmp->next = tmp->next->next;
		ret = tmp->next;
		tmp = tmp_b;
	}
	free(tmp->name);
	free(tmp);
	return (ret);
}

void    print_result(t_lem *lem)
{
	sort_way(lem->shorter);
	lem_on_way(lem);
	if (lem->opt.gway)
	{
		ft_putstr("\n### FOR ");
		ft_putnbr(lem->lems);
		ft_putstr(" LEMS IN ");
		ft_putnbr(lem->short_size);
		ft_putstr(" ROUNDS\n");
		show_way(lem->shorter);
	}
	ft_putchar('\n');
	lem_through(lem);
}
