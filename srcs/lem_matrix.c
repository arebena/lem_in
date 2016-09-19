
#include "lem_in.h"

void    matrix_show(char **matrix, int stase, int room, int way)
{
	int     i;
	int     e;
	char    str[20] = "\033[37;41mX\033[0m";
	char    str2[20] = "\033[35mX\033[0m";

	i = -1;
	ft_putchar('\n');
	while (e = -1, matrix[++i])
	{
		e = -1;
		ft_putstr("  ");
		while (matrix[i][++e] != -1)
		{
			str[8] = matrix[i][e] + 48;
			str2[5] = matrix[i][e] + 48;
			if (e > 0)
				ft_putchar(' ');
			if (i == room && way == e)
				ft_putstr(str);
			else if (i == e)
				ft_putstr((matrix[i][e]) ? "\033[31m1\033[0m" : "\033[31m0\033[0m")\
					;
			else if (matrix[i][e] < 0)
				ft_putstr("\033[34mO\033[0m");
			else if (matrix[i][e] > 1)
				ft_putstr(str2);
			else
				ft_putstr((matrix[i][e]) ? "\033[32m1\033[0m" : "\033[37m0\033[0m")\
					;
		}
		ft_putchar('\n');
	}
	(void)stase;
}

void    exit_buff(int *buff, int stase, int turn)
{
	int     i;
	char    str[80] = "\033[32m";


	i = 0;
	if (stase)
		while (++i != stase)
			ft_putstr("|");
	i = -1;
	ft_putstr("\033[1;32;44m \033[0m");
	while (buff[++i] != -1)
	{
		str[0] = 0;
		ft_strcat(str, "\033[1;32;44m");
		ft_strcat(str, ft_itoa(buff[i]));
		ft_strcat(str, "\033[0m");
		if (!stase)
			ft_putnbr(buff[i]);
		else
			ft_putstr(str);
		ft_putstr("\033[1;32;44m \033[0m");
	}
	ft_putstr(" - ");
	ft_putnbr(turn);
}

void    mark(t_lem *lem, int room, char flag)
{
	int     i;

	i = -1;
	while (lem->matrix[room][++i] != -1)
		if (lem->matrix[room][i])
		{
			lem->matrix[room][i] += flag;
			lem->matrix[i][room] += flag;
		}
}

void	matrix_valid(t_lem *lem, int *buff, int turn)
{
	int     *n_buff;
	
	lem->w_flag++;
	if (lem->w_flag == 2)
		lem->s_flag = ON;
	if (lem->opt.gway)
		exit_buff(buff, lem->w_flag, turn);
	way_upload(lem, buff, lem->w_flag, turn);
	mark(lem, 1, -1);
	n_buff = new_buffer(lem->mlen);
	matrix_run(lem, n_buff, 1, 1);
	free(n_buff);
	mark(lem, 1, 1);
	if (lem->opt.gway)
	{
		if (lem->w_flag == 1)
			ft_putendl("======================================");
		else if (lem->w_flag == 2)
			ft_putendl("--------------------------------------");
	}
	if (lem->w_flag == 1)
		lem->s_flag = OFF;
	lem->w_flag--;
}

void	show_rooms(t_lem *lem);

#include <stdio.h>

void	show_buffer(int *buff)
{
	int i = -1;
	while (buff[++i] >= 0)
		printf("for i = %d, buff = %d\n", i, buff[i]);
}

void    matrix_run(t_lem *lem, int *buff, int room, int turn)
{
	int     i;

	i = -1;
//	if (!room) ft_putendl("!!! VALID !!!");
//	printf("turn -> %d\n", turn);
	if (!room) {
		matrix_valid(lem, buff, turn);
	}
	else
		while (++i < lem->mlen)
		{
			buff[turn] = i;
			buff[turn + 1] = -1;
			if (lem->opt.mx)
			{
				if (lem->order_flag)
					ft_putstr(lem->m_esc);
//				matrix_show(lem->matrix, lem->w_flag, room, i);
				lem->order_flag = 1;
			}
			if (lem->matrix[room][i] == 1)
			{
				mark(lem, room, 1);
				matrix_run(lem, buff, i, turn + 1);
				mark(lem, room, -1);
			}
		}
}
