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

#include "../includes/lem_in.h"

#include <stdio.h>

void	puterror(int ecode)
{
	ft_putendl("ERROR");
	exit(-1);
	(void)ecode;
}

void	matrix_show(char **matrix, int stase, int room, int way)
{
	int		i;
	int		e;
	char	str[20] = "\033[37;41mX\033[0m";
	char	str2[20] = "\033[35mX\033[0m";

	i = -1;
	e = -1;
	if (stase)
		while (++e != stase)
			ft_putstr("================================\n");
	while (e = -1, matrix[++i])
	{
		while (matrix[i][++e] != -1)
		{
			str[8] = matrix[i][e] + 48;
			str2[5] = matrix[i][e] + 48;
			if (e > 0)
				ft_putchar(' ');
			if (i == room && way == e)
				ft_putstr(str);
			else if (i == e)
				ft_putstr((matrix[i][e]) ? "\033[31m1\033[0m" : "\033[31m0\033[0m");
			else if (matrix[i][e] < 0)
				ft_putstr("\033[34mO\033[0m");
			else if (matrix[i][e] > 1)
				ft_putstr(str2);
			else
				ft_putstr((matrix[i][e]) ? "\033[32m1\033[0m" : "\033[37m0\033[0m");
		}
		ft_putchar('\n');
	}
}

void	get_options(char *opt, t_lem *lem)
{
	ft_putendl(opt);
	(void)lem;
}

void	check_options(char **opt, t_lem *lem)
{
	int		i;

	i = 0;
	while (opt[++i])
		if (opt[i][0] == '-' && opt[i][1] && opt[i][1] != '-')
			get_options(&opt[i][1], lem);
}

void	exit_buff(int *buff, int stase)
{
	int		i;
	char	str[20] = "\033[32mX\033[0m";

	i = 0;
	if (stase)
		while (++i != stase)
			ft_putstr("| ");
	i = -1;
	while (buff[++i] != -1)
	{
		str[5] = buff[i] + 48;
		if (!stase)
			ft_putnbr(buff[i]);
		else
		{
			ft_putstr(str);
//			buff[1] = -1;
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
//	exit(0);
}

void	mark(t_lem *lem, int room, char flag)
{
	int		i;

	i = -1;
	while (lem->matrix[room][++i] != -1)
		if (lem->matrix[room][i])
		{
			lem->matrix[room][i] += flag;
			lem->matrix[i][room] += flag;
		}
}

void	matrix_run(t_lem *lem, int *buff, int room, int turn)
{
	int		i;

	i = -1;
	if (!room)
	{
//		ft_putendl("IN");
		lem->w_flag++;
		lem->ways++;
		exit_buff(buff, lem->w_flag);
		mark(lem, 1, -1);
//		matrix_show(lem->matrix, lem->w_flag);
		matrix_run(lem, buff, 1, 1);
		mark(lem, 1, 1);
//		if (lem->w_flag == 1)
//			ft_putendl("-------------------");
		lem->w_flag--;
//		ft_putendl("OUT");
//		matrix_show(lem->matrix, lem->w_flag);
	}
	else
		while (++i < lem->mlen)
		{
			ft_putstr("############# [ ");
				ft_putnbr(room);
				ft_putstr(" : ");
				ft_putnbr(i);
				ft_putstr(" ] ################\n");
				exit_buff(buff, 0);
				matrix_show(lem->matrix, lem->w_flag, room, i);
			if (lem->matrix[room][i] == 1)
			{
				
				buff[turn] = i;
				buff[turn + 1] = -1;
				//	matrix_show(lem->matrix, 0);
				//ft_putstr("------------------------------\n");
				mark(lem, room, 1);
				//			matrix_show(lem->matrix, lem->w_flag);
				//exit_buff(buff, 0);
				matrix_run(lem, buff, i, turn + 1);
				mark(lem, room, -1);
			}
		}
}

int		main(int ac, char **av)
{
	t_lem	lem;
	int		*buff;

	lem.ways = 0;
	lem.w_flag = 0;
	lem.rooms = (char **)malloc(sizeof(char *) * 3);
	lem.rooms[2] = NULL;
	if (map_anthill(&lem) == ERROR)
		puterror(1);
	if (ac > 1)
		check_options(av, &lem);
//	matrix_show(lem.matrix);
	buff = (int *)malloc(sizeof(int) * lem.mlen);
	buff[0] = 1;
	buff[1] = -1;
//	matrix_show(lem.matrix, 0);
	matrix_run(&lem, buff, 1, 1);
	printf("\nThere is %d possible ways...\n", lem.ways);
//	int i = -1;
//	while (lem.rooms[++i])
//		printf("rooms[%d] = %s\n", i, lem.rooms[i]);
//	printf("lems = %u\n", lem.lems);
	return (0);
}
