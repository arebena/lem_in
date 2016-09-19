/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:17:07 by arebena           #+#    #+#             */
/*   Updated: 2014/11/14 18:56:42 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char *src, char c)
{
	int len;

	len = 0;
	while (src[len] != c && src[len])
		len++;
	return (len);
}

static int	words_count(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			i = (i + word_len(&(str[i]), c)) - 1;
			count++;
		}
		i++;
	}
	return (count);
}

static void	*tab_malloc(char **tab, char *str, char c)
{
	int i;
	int i2;

	i = -1;
	i2 = 0;
	if (!(tab = (char **)malloc(8 * (words_count(str, c) + 1))))
		return (NULL);
	while (str[++i] != 0)
		if (str[i] != c)
		{
			if (!(tab[i2] = (char *)malloc(word_len(&(str[i]), c) + 1)))
				return (NULL);
			i2++;
			i = (i + word_len(&(str[i]), c)) - 1;
		}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i2;
	char	**tab;

	i = -1;
	tab = NULL;
	if (i2 = 0, s == NULL)
		return (NULL);
	if (!(tab = tab_malloc(tab, (char *)s, c)))
		return (NULL);
	while (s[++i] != 0)
		if (s[i] != c)
		{
			tab[i2] = ft_strndup((char *)&(s[i]), word_len((char *)&(s[i]), c));
			i = (i + word_len((char *)&(s[i]), c)) - 1;
			i2++;
		}
	tab[i2] = NULL;
	return (tab);
}
