/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:55:04 by arebena           #+#    #+#             */
/*   Updated: 2014/11/24 20:25:05 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *tmp_nod;

	new_lst = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		tmp_nod = ft_noddup(lst, NULL);
		ft_lstaddend(&new_lst, ft_noddup((*f)(tmp_nod), NULL));
		lst = lst->next;
		free(tmp_nod->content);
		free(tmp_nod);
		tmp_nod = NULL;
	}
	ft_lstaddend(&new_lst, NULL);
	return (new_lst);
}
