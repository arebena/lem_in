/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:52:29 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:30:08 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	char	*temp;
	char	*tmp;

	if (i = 0, (char)n < 0)
		return (NULL);
	temp = dst;
	tmp = (char *)src;
	while (n--)
		if (temp[i] = tmp[i], tmp[i++] == (char)c)
			return ((void *)&(temp[i]));
	return (NULL);
}
