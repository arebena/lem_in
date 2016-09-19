/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 17:00:06 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 14:18:48 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodswap(t_list *nod1, t_list *nod2)
{
	t_list *tmp_nod;

	if (nod1 == NULL || nod2 == NULL						\
		|| !(tmp_nod = (t_list *)malloc(sizeof(t_list *))))
		return ;
	tmp_nod->content = nod2->content;
	tmp_nod->content_size = nod2->content_size;
	nod2->content = nod1->content;
	nod2->content_size = nod1->content_size;
	nod1->content = tmp_nod->content;
	nod1->content_size = tmp_nod->content_size;
	return ;
}
