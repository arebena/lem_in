/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:26:57 by arebena           #+#    #+#             */
/*   Updated: 2014/11/24 20:26:29 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *tmp_lst;

	tmp_lst = *alst;
	if (alst == NULL)
		return ;
	else if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
	if (new != NULL)
		new->next = NULL;
}
