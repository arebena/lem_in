/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:50:24 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 13:51:18 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	temp[ft_strlen(str) + 1];

	start = -1;
	end = ft_strlen(str);
	while (++start <= --end)
	{
		temp[end] = str[start];
		temp[start] = str[end];
	}
	temp[ft_strlen(str)] = 0;
	str = temp;
	return (str);
}
