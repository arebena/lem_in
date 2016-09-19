/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrewind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 15:50:46 by arebena           #+#    #+#             */
/*   Updated: 2015/06/28 16:32:46 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lstrewind(t_list **lst, t_list **nod)
{
	t_list *tmp;

	tmp = *lst;
	if (*nod == *lst)
		return (NULL);
	while (tmp->next != *nod)
		tmp = tmp->next;
	return (nod = &tmp);
}
