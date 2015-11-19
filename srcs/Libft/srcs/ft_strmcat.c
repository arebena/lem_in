/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:29:50 by arebena           #+#    #+#             */
/*   Updated: 2014/12/29 17:36:56 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmcat(char *dst, const char *src)
{
	char *new_str;

	if (dst == NULL && src == NULL)
		return (NULL);
	else if (new_str = NULL, dst == NULL)
		return (ft_strdup(src));
	else if (src == NULL)
		return (dst);
	new_str = (char *)malloc(ft_strlen(dst) + ft_strlen(src) + 1);
	ft_strcat(ft_strcpy(new_str, dst), src);
	if (dst)
		free(dst);
	dst = NULL;
	return (new_str);
}
