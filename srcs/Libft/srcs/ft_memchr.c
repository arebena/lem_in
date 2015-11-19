/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:31:04 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:30:57 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	if (i = 0, (int)n < 0)
		return (NULL);
	while (i < (int)n)
		if (tmp[i++] == (char)c)
			return ((void *)&(tmp[--i]));
	return (NULL);
}
