/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:30:24 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 17:52:03 by arebena          ###   ########.fr       */
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

void	matrix_show(char **matrix)
{
	int		i;
	int		e;

	i = -1;
	ft_putstr("== MATRICE ==\n");
	while (e = -1, matrix[++i])
	{
//		ft_putchar('[');
//		ft_putnbr(i);
//		ft_putstr("] ");
		while (matrix[i][++e] != -1)
		{
//			ft_putstr("LINE");
			if (e > 0)
				ft_putchar(' ');
			if (i == e)
				ft_putstr((matrix[i][e]) ? "\033[31m1\033[0m" : "\033[31m0\033[0m");
			else
				ft_putstr((matrix[i][e]) ? "\033[34;43m1\033[0m" : "0");
		}
		ft_putchar('\n');
	}			
}

int		main(void)
{
	t_lem	lem;

	lem.rooms = (char **)malloc(sizeof(char *) * 3);
	lem.rooms[2] = NULL;
	if (map_anthill(&lem) == ERROR)
		puterror(1);
	matrix_show(lem.matrix);
	matrix_run(lem);
//	int i = -1;
//	while (lem.rooms[++i])
//		printf("rooms[%d] = %s\n", i, lem.rooms[i]);
//	printf("lems = %u\n", lem.lems);
	return (0);
}
