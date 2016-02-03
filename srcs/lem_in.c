/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:30:24 by arebena           #+#    #+#             */
/*   Updated: 2015/11/21 08:07:15 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

void	puterror(int ecode)
{
	ft_putendl("ERROR");
	exit(-1);
	(void)ecode;
}

void	get_options(char *opt, t_lem *lem)
{
	if (ft_strchr(opt, 'm'))
		lem->opt.mx = ON;
	if (ft_strchr(opt, 'w'))
		lem->opt.gway = ON;
}

void	check_options(char **opt, t_lem *lem)
{
	int		i;

	i = 0;
	while (opt[++i])
		if (opt[i][0] == '-' && opt[i][1] && opt[i][1] != '-')
			get_options(&opt[i][1], lem);
}

int		*new_buffer(int len)
{
	int		*buff;
	
	buff = (int *)malloc(sizeof(int) * len);
	buff[0] = 1;
	buff[1] = -1;
	return (buff);
}

void	show_way(t_way *way)
{
	t_way	*tmp;
	int		stase = 1;
	int		i;
	int		*buff;
	char	str[80] = "\033[32m";
	char	*itmp;
	
	tmp = way;
	while (tmp)
	{
		i = 0;
		if (stase)
			while (++i != stase)
				ft_putstr("|");
		i = -1;
		ft_putstr("\033[1;30;46m \033[0m");
		buff = tmp->way;
		while (buff[++i] != -1)
		{
			str[0] = 0;
			itmp = ft_itoa(buff[i]);
			ft_strcat(str, "\033[1;30;46m");
			ft_strcat(str, itmp);
			ft_strcat(str, "\033[0m");
			if (!stase)
				ft_putnbr(buff[i]);
			else
				ft_putstr(str);
			free(itmp);
			ft_putstr("\033[1;30;46m \033[0m");
		}
		ft_putstr(" - ");
		ft_putnbr(tmp->len);
		ft_putstr(" - ");
		ft_putnbr(tmp->lem_on);
		ft_putchar('\n');
		tmp = tmp->next;
		stase++;
	}
}

int		*way_dup(int *way, int len, int flag)
{
	int		*n_way;
	int		i;

	i = flag - 1;
	n_way = (int *)malloc(sizeof(int) * (len + ((flag) ? 0 : 1)));
	while (way[++i] != -1)
		n_way[i - flag] = way[i];
	n_way[len - flag] = -1;
	return (n_way);
}

t_way	*new_way(int *buff, int turn, int flag);

t_way	*big_way_dup(t_way *way)
{
	t_way	*n_way;
	t_way	*n_tmp;
	t_way	*tmp;

	n_way = new_way(way->way, way->len, OFF);
	tmp = way->next;
	n_tmp = n_way;
	while (tmp)
	{
		n_tmp->next = new_way(tmp->way, tmp->len, OFF);
		n_tmp = n_tmp->next;
		tmp = tmp->next;
	}
	return (n_way);
}

void	way_modif(t_way *way, int *buff, int turn)
{
	t_way	*tmp;
	t_way	*next;

	tmp = way->next;
	free(way->way);
	way->way = way_dup(buff, turn, ON);
	way->len = turn - 1;
	way->next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->way);
		free(tmp);
		tmp = next;
	}
}

int		ft_ceil(float n)
{
	return ((n-(int)(n)) > 0 ? (int)(n+1) : (int)(n));
}

t_way	*new_way(int *buff, int turn, int flag)
{
	t_way	*n_way;

	n_way = (t_way *)malloc(sizeof(t_way));
	n_way->way = way_dup(buff, turn, flag);
	n_way->len = turn - flag;
	n_way->next = NULL;
	return (n_way);
}

void	new_shorter(t_lem *lem, int n_size)
{
	t_way	*tmp;
	t_way	*next;
	
	if (lem->shorter)
	{
		tmp = lem->shorter;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->way);
			free(tmp);
			tmp = next;
		}
		lem->shorter = NULL;
	}
	lem->shorter = big_way_dup(lem->way);
	lem->short_size = n_size;
}

void	way_check(t_lem *lem)
{
	t_way	*tmp;
	char	*sol;
	int		n;
	int		e;
	int		s;

	tmp = lem->way;
	n = e = 0;
	while (tmp)
	{
		e += tmp->len - 1;
		n++;
		tmp = tmp->next;
	}
	s = ft_ceil((e + lem->lems) / (float)n);
	if (s < lem->short_size || lem->short_size < 0)
		new_shorter(lem, s);
	if (lem->opt.gway)
	{
		sol = ft_itoa(s);
		ft_putstr(" - \033[1;30;46m");
		ft_putstr(sol);
		ft_putstr("\033[0m\n");
		free(sol);
	}
}

void	way_upload(t_lem *lem, int *buff, int stase, int turn)
{
	t_way	*tmp;
	t_way	*back;
	int		i;

	i = 0;
	tmp = lem->way;
	if(!lem->way && stase == 1)
		lem->way = new_way(buff, turn, ON);
	else
	{
		while (++i != stase)
		{
			back = tmp;
			tmp = tmp->next;
		}
		if (tmp)
			way_modif(tmp, buff, turn);
		else
			back->next = new_way(buff, turn, ON);
	}
	way_check(lem);
}

int		main(int ac, char **av)
{
	t_lem	lem;
	int		*buff;

	lem.w_flag = OFF;
	lem.s_flag = OFF;
	lem.opt.mx = OFF;
	lem.opt.gway = OFF;
	lem.way = NULL;
	lem.shorter = NULL;
	lem.lem_in = NULL;
	lem.short_size = -1;
	lem.rooms = (char **)malloc(sizeof(char *) * 3);
	lem.rooms[0] = ft_strdup("void");
	lem.rooms[1] = ft_strdup("void");
	lem.rooms[2] = NULL;
	if (map_anthill(&lem) == ERROR)
		puterror(1);
	if (ac > 1)
		check_options(av, &lem);
	buff = new_buffer(lem.mlen);
	lem.order_flag = 0;
	matrix_run(&lem, buff, 1, 1);
	print_result(&lem);
	return (0);
}
