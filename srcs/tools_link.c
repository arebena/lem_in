/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 15:55:17 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 14:45:19 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*dup_tab(int *tab)
{
	int		i;
	int		*n_tab;

	i = 0;
	while (tab[i] != -1)
		i++;
	n_tab = (int *)malloc(sizeof(int) * (i + 1));
	i = -1;
	while (tab[++i] != -1)
		n_tab[i] = tab[i];
	n_tab[i] = -1;
	return (n_tab);
}

char	islink(char *line)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (line[++i])
	{
		if (line[i] == '-')
		{
			if (!(line[i + 1]))
				return (0);
			flag++;
		}
	}
	return ((flag == 1) ? 1 : 0);
}
