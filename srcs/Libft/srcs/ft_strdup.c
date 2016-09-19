/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:22:54 by arebena           #+#    #+#             */
/*   Updated: 2014/11/12 21:16:20 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	if ((cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*cpy))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}
