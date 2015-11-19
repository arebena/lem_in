/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:24:18 by arebena           #+#    #+#             */
/*   Updated: 2015/02/06 18:40:48 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int e;
	int	o;

	if (i = -1, s2[0] == 0)
		return ((char *)s1);
	while (e = 0, s1[++i] != 0)
		if (o = i, s1[i] == s2[e])
			while (s1[o] == s2[e++])
				if (o++, s2[e] == 0)
					return ((char *)&(s1[o - e]));
	return (NULL);
}
