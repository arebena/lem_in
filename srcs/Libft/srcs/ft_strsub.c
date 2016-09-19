/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:59:21 by arebena           #+#    #+#             */
/*   Updated: 2015/02/06 20:26:45 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s == NULL || start >= ft_strlen(s))
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (!(str = ft_strndup(&(s[start]), len)))
		return (NULL);
	return (str);
}
