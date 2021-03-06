/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:08:39 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 15:02:09 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*e;

	if (i = 0, (char)n <= 0)
		return ;
	e = s;
	while (n--)
		e[i++] = 0;
	s = e;
	return ;
}
