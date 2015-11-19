/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbemb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:59:03 by arebena           #+#    #+#             */
/*   Updated: 2014/11/29 16:01:21 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbemb(t_list **lst, t_list **lst_spot, t_list *new_nod)
{
	t_list *tmp;

	if (lst == NULL || new_nod == NULL || *lst == NULL || lst_spot == NULL \
		|| *lst_spot == NULL)
		return ;
	if (*lst == *lst_spot)
		ft_lstadd(lst, ft_nodcut(lst, &new_nod));
	else
	{
		tmp = *lst;
		while (tmp->next != *lst_spot)
			tmp = tmp->next;
		tmp->next = ft_nodcut(lst, &new_nod);
		tmp->next->next = *lst_spot;
	}
}
