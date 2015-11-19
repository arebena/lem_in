/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:41:20 by arebena           #+#    #+#             */
/*   Updated: 2015/02/06 20:20:20 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int e;
	int flag;
	int count;

	e = 0;
	if (i = 0, (int)ft_strlen(dst) < (int)size)
		count = ft_strlen(dst) + ft_strlen((char *)src);
	else if (flag = -1, 1)
		count = (int)size + ft_strlen((char *)src);
	flag = 0;
	while ((i - 1) != (int)size - 1 && flag != -1)
	{
		if (flag == 1 && src[e])
		{
			dst[i - 1] = src[e++];
			dst[i] = 0;
		}
		else if (dst[i] == 0 && (i) < (int)size)
			flag = 1;
		i++;
	}
	if (flag == 1)
		dst[i - 1] = 0;
	return (count);
}
