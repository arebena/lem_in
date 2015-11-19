/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:44:24 by arebena           #+#    #+#             */
/*   Updated: 2014/12/13 15:36:45 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_nodcut(t_list **lst, t_list **n_to_cut)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp->next != *n_to_cut)
		tmp = tmp->next;
	tmp->next = (*n_to_cut)->next;
	(*n_to_cut)->next = NULL;
	return (*n_to_cut);
}
