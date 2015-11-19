/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduptab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:44:04 by arebena           #+#    #+#             */
/*   Updated: 2014/12/09 11:23:07 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lstduptab(t_list **lst)
{
	int		i;
	char	**new_tab;
	t_list	*tmp_l;

	i = 0;
	tmp_l = *lst;
	while (i++, tmp_l)
		tmp_l = tmp_l->next;
	tmp_l = *lst;
	if (!(new_tab = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	while (tmp_l)
	{
		if (!(new_tab[i] = ft_strdup((char *)tmp_l->content)))
			return (NULL);
		tmp_l = tmp_l->next;
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
