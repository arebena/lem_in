/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:39:03 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 00:36:07 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*cpy;

	if (!(cpy = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i] && i != (int)n)
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}
