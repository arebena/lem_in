/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noddel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:53:56 by arebena           #+#    #+#             */
/*   Updated: 2014/12/29 17:45:48 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_noddel(t_list **lst, t_list **n_to_del)
{
	t_list *tmp;

	if (*lst == NULL || *n_to_del == NULL)
		return (NULL);
	tmp = *lst;
	if (tmp == *n_to_del)
	{
		*lst = (*n_to_del)->next;
		tmp = *lst;
	}
	else
	{
		while (tmp && tmp->next != *n_to_del)
			tmp = tmp->next;
		tmp->next = (*n_to_del)->next;
		if (tmp->next)
			tmp = tmp->next;
	}
	if ((*n_to_del)->content)
		free((*n_to_del)->content);
	(*n_to_del)->content = NULL;
	if (*n_to_del)
		free(*n_to_del);
	*n_to_del = NULL;
	return (tmp);
}
