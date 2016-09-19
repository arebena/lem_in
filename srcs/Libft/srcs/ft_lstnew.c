/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 21:34:25 by arebena           #+#    #+#             */
/*   Updated: 2014/11/24 18:57:47 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;
	int		bytes_nbr;

	bytes_nbr = content_size / sizeof(*content);
	if (!(new_node = (t_list *)malloc(sizeof(t_list)))			\
		|| !(new_node->content = (void *)malloc(content_size)))
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		ft_memcpy(new_node->content, content, bytes_nbr);
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}
