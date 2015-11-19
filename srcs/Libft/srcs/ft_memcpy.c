/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:34:55 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:33:14 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*tmp;

	if (i = -1, (int)n == 0)
		return (dst);
	temp = dst;
	tmp = (char *)src;
	while (i += 1, n-- != 0)
		temp[i] = tmp[i];
	dst = (void *)temp;
	return (dst);
}
