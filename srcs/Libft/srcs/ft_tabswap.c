/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:26:07 by arebena           #+#    #+#             */
/*   Updated: 2014/12/02 16:28:11 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabswap(char **tab, int ying, int yang)
{
	char *tmp;

	tmp = tab[ying];
	tab[ying] = tab[yang];
	tab[yang] = tmp;
}
