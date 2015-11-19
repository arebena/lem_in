/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpylst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:45:36 by arebena           #+#    #+#             */
/*   Updated: 2014/12/29 18:23:41 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabcpylst(char **tab, t_list **lst)
{
	int		i;
	t_list	*tmp_l;

	i = -1;
	tmp_l = *lst;
	while (tab[++i] && tmp_l)
	{
		free(tmp_l->content);
		tmp_l->content = ft_strdup(tab[i]);
		tmp_l->content_size = ft_strlen(tab[i]) + 1;
		tmp_l = tmp_l->next;
	}
}
