/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:16:48 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:49:04 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	tmp1[ft_strlen(s1) + 1];
	char	tmp2[ft_strlen(s2) + 1];

	i = 0;
	if (n == 0)
		return (0);
	ft_strcpy(tmp1, s1);
	ft_strcpy(tmp2, s2);
	while (tmp1[i] == tmp2[i] && tmp1[i] && tmp2[i] && n-- > 1)
		i++;
	if (tmp1[i] == 0)
		if (tmp2[i] < 0)
			return (tmp2[i]);
	if (tmp2[i] == 0)
		if (tmp1[i] < 0)
			return (-(tmp1[i]));
	return (tmp1[i] - tmp2[i]);
}
