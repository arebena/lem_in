/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:53:18 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:50:07 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while (n-- > 0)
	{
		if (src[++i] == 0)
			flag = 1;
		if (flag == 0)
			dst[i] = src[i];
		else
			dst[i] = 0;
	}
	return (dst);
}
