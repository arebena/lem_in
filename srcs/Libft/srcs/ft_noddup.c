/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noddup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:17:26 by arebena           #+#    #+#             */
/*   Updated: 2014/11/24 20:26:54 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_noddup(t_list *nod_src, t_list *next)
{
	t_list		*new_nod;

	if (nod_src == NULL)
		return (new_nod = NULL);
	else if (!(new_nod = ft_lstnew(nod_src->content, nod_src->content_size)))
		return (NULL);
	new_nod->next = next;
	return (new_nod);
}
