/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:06:55 by arebena           #+#    #+#             */
/*   Updated: 2015/02/06 19:50:17 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*srcb;
	char	*dstb;

	if (i = -1, (char)len == 0)
		return (dst);
	dstb = ft_strdup((char *)dst);
	srcb = (char *)src;
	while (++i < (int)len)
		dstb[i] = srcb[i];
	ft_memcpy((char *)dst, dstb, len);
	free(dstb);
	return ((void *)dst);
}
