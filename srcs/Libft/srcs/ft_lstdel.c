/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:07:20 by arebena           #+#    #+#             */
/*   Updated: 2014/11/22 16:21:01 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **tmp_lst;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	tmp_lst = alst;
	while (*tmp_lst != NULL)
	{
		(*del)((*tmp_lst)->content, (*tmp_lst)->content_size);
		free(*tmp_lst);
		(*tmp_lst) = (*tmp_lst)->next;
	}
	*alst = NULL;
}
