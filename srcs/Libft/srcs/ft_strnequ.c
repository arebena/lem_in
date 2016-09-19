/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:22:35 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 17:56:55 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((s1[i] == 0 && s2[i] != 0) || (s2[i] == 0 && s1[i] != 0))
		return (0);
	while ((s1 || s2) && n-- != 0)
		if (i++, s1[i] != s2[i])
			return (0);
	return (1);
}
