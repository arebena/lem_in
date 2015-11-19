/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stritab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:56:24 by arebena           #+#    #+#             */
/*   Updated: 2015/03/23 16:10:30 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		*init_itab(int len)
{
	int		*itab;

	itab = (int *)malloc(sizeof(int) * (len + 1));
	itab[0] = len;
	return (itab);
}

int				*ft_stritab(char *str)
{
	int		i;
	int		i_max;
	int		*itab;
	char	flag;

	flag = 0;
	itab = NULL;
	while (i = 0, flag < 2)
	{
		i_max = 0;
		while (str[i])
			if (ft_isnbr(&(str[i])))
			{
				i_max++;
				if (flag)
					itab[i_max] = ft_atoi(&(str[i]));
				i += ft_nbrlen(&(str[i]));
			}
			else
				i++;
		if (!flag++ && i_max)
			itab = init_itab(i_max);
	}
	return (itab);
}
