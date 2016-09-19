/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:40:09 by arebena           #+#    #+#             */
/*   Updated: 2015/02/06 19:23:41 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*s1b;
	char	*s2b;

	i = 0;
	s1b = (char *)s1;
	s2b = (char *)s2;
	while (s1b[i] == s2b[i] && n-- != 0)
		i++;
	if (s1b[i] == 0 && s2b[i] != 0 && !i)
		return (-1);
	else if (s2b[i] == 0 && s1b[i] != 0 && !i)
		return (1);
	else if (n == 0)
		return (0);
	else
		return (((s1b[i] > 0) ? s1b[i] : -s1b[i]) - s2b[i]);
}
