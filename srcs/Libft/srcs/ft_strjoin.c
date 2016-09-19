/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:22:26 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 18:55:57 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || (s1[0] == 0 && s2[0] != 0))
		return (str = ft_strdup(s2));
	else if (s2 == NULL || (s2[0] == 0 && s1[0] != 0))
		return (str = ft_strdup(s1));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, (char *)s2);
	return (str);
}
