/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodemb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:39:17 by arebena           #+#    #+#             */
/*   Updated: 2014/11/29 12:58:12 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodemb(t_list **lst, t_list *new_nod)
{
	t_list *tmp;

	if (lst == NULL || new_nod == NULL || *lst == NULL)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = new_nod;
	new_nod->next = tmp;
}
