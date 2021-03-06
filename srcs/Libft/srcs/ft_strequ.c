/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:17:20 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 18:00:01 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((s1[i] == 0 && s2[i] != 0) || (s2[i] == 0 && s1[i] != 0))
		return (0);
	while (s1[i] || s2[i])
		if (i++, s1[i] != s2[i])
			return (0);
	return (1);
}
