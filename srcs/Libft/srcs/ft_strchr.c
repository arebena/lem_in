/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:25:20 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:42:29 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != 0)
		if (s[i++] == (char)c)
			return ((char *)&(s[i - 1]));
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (NULL);
}
