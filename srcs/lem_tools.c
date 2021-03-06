
#include "lem_in.h"

int     lem_process(t_lem *lem, t_lemin **lem_in, t_way *way, int flag)
{
	char    out;
	t_lemin *tmp;

	out = OFF;
	tmp = *lem_in;
	tmp->pos++;
	if (flag)
		ft_putchar(' ');
	ft_putstr(tmp->name);
	ft_putchar('-');
	ft_putstr(ROOMS[way->way[tmp->pos]]);
//	ft_putstr(" [ ");
//	ft_putnbr(way->way[tmp->pos]);
//	ft_putstr(" ]");
	if (!way->way[tmp->pos])
	{
		*lem_in = lem_del(lem, tmp->id);
		out = ON;
	}
	return (out);
}

t_way   *get_lem_way(t_lem *lem, int id_way)
{
	int     i;
	t_way   *way;

	i = 0;
	way = lem->shorter;
	while (++i != id_way)
		way = way->next;
	return (way);
}

void    add_lem_to_end(t_lem *lem, t_lemin *n_lem)
{
	t_lemin     *tmp;

	if (!lem->lem_in)
		lem->lem_in = n_lem;
	else
	{
		tmp = lem->lem_in;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n_lem;
	}
}

void    add_lem(t_lem *lem, int id, int flag)
{
	static int  id_lem = 1;
	t_lemin     *n_lem;
	t_way       *way;
	char        *name;
	char        *id_c;

	name = ft_strdup("L");
	id_c = ft_itoa(id_lem);
	name = ft_strmcat(name, id_c);
	free(id_c);
	n_lem = (t_lemin *)malloc(sizeof(t_lemin));
	n_lem->id = id_lem;
	n_lem->name = name;
	n_lem->id_way = id;
	n_lem->pos = 0;
	n_lem->next = NULL;
	add_lem_to_end(lem, n_lem);
	way = get_lem_way(lem, id);
	if (flag)
		ft_putchar(' ');
	ft_putstr(name);
	ft_putchar('-');
	ft_putstr(ROOMS[way->way[0]]);
//	ft_putstr(" [ ");
//	ft_putnbr(way->way[0]);
//	ft_putstr(" ]");
	id_lem++;
}

void    lem_through(t_lem *lem)
{
	t_lemin *tmp;
	t_way   *way;
	int     ret;
	int     left;
	int     flag;

	left = lem->lems;
	while (left)
	{
		flag = OFF;
		tmp = lem->lem_in;
		while (tmp)
		{
			way = get_lem_way(lem, tmp->id_way);
			ret = lem_process(lem, &tmp, way, flag);
			left -= ret;
			if (!ret)
				tmp = tmp->next;
			flag = ON;
		}
		way = lem->shorter;
		while (way)
		{
			if (way->lem_on)
			{
				add_lem(lem, way->id, flag);
				way->lem_on--;
				flag = ON;
			}
			way = way->next;
		}
		ft_putchar('\n');
	}
}
