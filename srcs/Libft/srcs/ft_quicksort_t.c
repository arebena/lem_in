/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:22:15 by arebena           #+#    #+#             */
/*   Updated: 2015/03/23 16:36:05 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_partition(char **tab, int low, int high)
{
	int		left;
	int		right;
	char	*pivot_item;

	left = low;
	right = high;
	pivot_item = tab[low];
	while (left < right)
	{
		while (ft_strcmp(tab[left], pivot_item) <= 0 && left < high)
			left++;
		while (ft_strcmp(tab[right], pivot_item) > 0)
			right--;
		if (left < right)
			ft_tabswap(tab, left, right);
	}
	tab[low] = tab[right];
	tab[right] = pivot_item;
	return (right);
}

static void	ft_quicksort_way(char **tab, int low, int high)
{
	int		pivot;

	if (high > low)
	{
		pivot = ft_partition(tab, low, high);
		ft_quicksort_way(tab, low, pivot - 1);
		ft_quicksort_way(tab, pivot + 1, high);
	}
}

char		**ft_quicksort_t(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	ft_quicksort_way(tab, 0, i - 1);
	return (tab);
}
